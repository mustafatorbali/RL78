//=====================================================================//
/*!	@file
	@brief	A/D 変換のサンプル @n
			P22/ANI2(54)、P23/ANI3(53) を変換して表示
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2016 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RL78/blob/master/LICENSE
*/
//=====================================================================//
#include <cstdint>
#include "common/port_utils.hpp"
#include "common/fifo.hpp"
#include "common/uart_io.hpp"
#include "common/format.hpp"
#include "common/itimer.hpp"
#include "common/adc_io.hpp"
#include "common/task.hpp"

namespace {
	void wait_()
	{
		asm("nop");
	}

	typedef utils::fifo<uint8_t, 32> buffer;
	device::uart_io<device::SAU02, device::SAU03, buffer, buffer> uart_;

	device::itimer<uint8_t> itm_;

	// 最終チャネル番号＋１を設定
	typedef device::adc_io<4, utils::null_task> adc;
	adc adc_;
}

/// 割り込みベクターの定義
const void* ivec_[] __attribute__ ((section (".ivec"))) = {
	/*  0 */  nullptr,
	/*  1 */  nullptr,
	/*  2 */  nullptr,
	/*  3 */  nullptr,
	/*  4 */  nullptr,
	/*  5 */  nullptr,
	/*  6 */  nullptr,
	/*  7 */  nullptr,
	/*  8 */  nullptr,
	/*  9 */  nullptr,
	/* 10 */  nullptr,
	/* 11 */  nullptr,
	/* 12 */  nullptr,
	/* 13 */  nullptr,
	/* 14 */  nullptr,
	/* 15 */  nullptr,
	/* 16 */  reinterpret_cast<void*>(uart_.send_task),  // UART1-TX
	/* 17 */  reinterpret_cast<void*>(uart_.recv_task),  // UART1-RX
	/* 18 */  reinterpret_cast<void*>(uart_.error_task), // UART1-ER
	/* 19 */  nullptr,
	/* 20 */  nullptr,
	/* 21 */  nullptr,
	/* 22 */  nullptr,
	/* 23 */  nullptr,
	/* 24 */  reinterpret_cast<void*>(adc_.task),
	/* 25 */  nullptr,
	/* 26 */  reinterpret_cast<void*>(itm_.task),
};


extern "C" {
	void sci_putch(char ch)
	{
		uart_.putch(ch);
	}

	void sci_puts(const char* str)
	{
		uart_.puts(str);
	}
};


int main(int argc, char* argv[])
{
	utils::port::pullup_all();  ///< 安全の為、全ての入力をプルアップ

	device::PM4.B3 = 0;  // output

	{
		uint8_t intr_level = 1;
		uart_.start(115200, intr_level);
	}

	{
		uint8_t intr_level = 1;
		itm_.start(60, intr_level);
	}

	{
		device::PM2.B2 = 1;
		device::PM2.B3 = 1;
		uint8_t intr_level = 1;  // 割り込み設定
		adc_.start(adc::REFP::VDD, adc::REFM::VSS, intr_level);
	}

	uart_.puts("Start RL78/G13 A/D Convert sample\n");

	uint8_t n = 0;
	uint8_t t = 0;
	while(1) {
		itm_.sync();
		adc_.start_scan(2);  // スキャン開始チャネル

		adc_.sync();  // スキャン終了待ち

		if(t >= 30) {
			auto val = adc_.get(2);
			val >>= 6;
#if 1
			uint32_t vol = static_cast<uint32_t>(val) * 1024 / 310;  // Vref: 3.3V とした場合の電圧
			utils::format("A/D CH2: %4.2:10y [V] (%d)\n") % vol % val;
#else
			float vol = static_cast<float>(val) * 3.3f / 1023.0f;
			utils::format("A/D CH2: %4.2f [V] (%d)\n") % vol % val;
#endif
			val = adc_.get(3);
			val >>= 6;
#if 1
			vol = static_cast<uint32_t>(val) * 1024 / 310;
			utils::format("A/D CH3: %4.2:10y [V] (%d)\n") % vol % val;
#else
			vol = static_cast<float>(val) * 3.3f / 1023.0f;
			utils::format("A/D CH3: %4.2f [V] (%d)\n") % vol % val;
#endif
			t = 0;
		} else {
			++t;
		}

		++n;
		if(n >= 30) n = 0;
		device::P4.B3 = n < 10 ? false : true; 	
	}
}
