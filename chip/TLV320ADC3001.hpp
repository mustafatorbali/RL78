#pragma once
//=====================================================================//
/*!	@file
	@brief	TLV320ADC3001 ドライバー・クラス @n
			Low-Power Stereo ADC With Embedded miniDSP
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2017 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RL78/blob/master/LICENSE
*/
//=====================================================================//
#include <cstdint>
#include "common/format.hpp"

namespace chip {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  TLV320ADC3001 テンプレートクラス
		@param[in]	I2C_IO	I2C I/O クラス
		@param[in]	DEV_ADR	I2C デバイス・アドレス @n
					I2C_ADR1:0, I2C_ADR0:0 ---> 0b0011000 @n
					I2C_ADR1:0, I2C_ADR0:1 ---> 0b0011001 @n
					I2C_ADR1:1, I2C_ADR0:0 ---> 0b0011010 @n
					I2C_ADR1:1, I2C_ADR0:1 ---> 0b0011011
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class I2C_IO, uint8_t DEV_ADR = 0b0011000>
	class TLV320ADC3001 {
	public:

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  Interface 型
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class INF : uint8_t {
			I2S_16_SLAVE  = 0b00000000,	///< I2S/16Bits, BCLK:inp, WCLK:inp
			I2S_16_MASTER = 0b00001100,	///< I2S/16Bits, BCLK:out, WCLK:out
			I2S_20_SLAVE  = 0b00010000,	///< I2S/20Bits, BCLK:inp, WCLK:inp
			I2S_20_MASTER = 0b00011100,	///< I2S/20Bits, BCLK:out, WCLK:out
			I2S_24_SLAVE  = 0b00100000,	///< I2S/16Bits, BCLK:inp, WCLK:inp
			I2S_24_MASTER = 0b00101100,	///< I2S/16Bits, BCLK:out, WCLK:out
			I2S_32_SLAVE  = 0b00110000,	///< I2S/16Bits, BCLK:inp, WCLK:inp
			I2S_32_MASTER = 0b00111100,	///< I2S/16Bits, BCLK:out, WCLK:out

			DSP_16_SLAVE  = 0b01000000,	///< DSP/16Bits, BCLK:inp, WCLK:inp
			DSP_16_MASTER = 0b01001100,	///< DSP/16Bits, BCLK:out, WCLK:out
			DSP_20_SLAVE  = 0b01010000,	///< DSP/20Bits, BCLK:inp, WCLK:inp
			DSP_20_MASTER = 0b01011100,	///< DSP/20Bits, BCLK:out, WCLK:out
			DSP_24_SLAVE  = 0b01100000,	///< DSP/16Bits, BCLK:inp, WCLK:inp
			DSP_24_MASTER = 0b01101100,	///< DSP/16Bits, BCLK:out, WCLK:out
			DSP_32_SLAVE  = 0b01110000,	///< DSP/16Bits, BCLK:inp, WCLK:inp
			DSP_32_MASTER = 0b01111100,	///< DSP/16Bits, BCLK:out, WCLK:out

			RJF_16_SLAVE  = 0b10000000,	///< RJF/16Bits, BCLK:inp, WCLK:inp
			RJF_16_MASTER = 0b10001100,	///< RJF/16Bits, BCLK:out, WCLK:out
			RJF_20_SLAVE  = 0b10010000,	///< RJF/20Bits, BCLK:inp, WCLK:inp
			RJF_20_MASTER = 0b10011100,	///< RJF/20Bits, BCLK:out, WCLK:out
			RJF_24_SLAVE  = 0b10100000,	///< RJF/16Bits, BCLK:inp, WCLK:inp
			RJF_24_MASTER = 0b10101100,	///< RJF/16Bits, BCLK:out, WCLK:out
			RJF_32_SLAVE  = 0b10110000,	///< RJF/16Bits, BCLK:inp, WCLK:inp
			RJF_32_MASTER = 0b10111100,	///< RJF/16Bits, BCLK:out, WCLK:out

			LJF_16_SLAVE  = 0b11000000,	///< LJF/16Bits, BCLK:inp, WCLK:inp
			LJF_16_MASTER = 0b11001100,	///< LJF/16Bits, BCLK:out, WCLK:out
			LJF_20_SLAVE  = 0b11010000,	///< LJF/20Bits, BCLK:inp, WCLK:inp
			LJF_20_MASTER = 0b11011100,	///< LJF/20Bits, BCLK:out, WCLK:out
			LJF_24_SLAVE  = 0b11100000,	///< LJF/16Bits, BCLK:inp, WCLK:inp
			LJF_24_MASTER = 0b11101100,	///< LJF/16Bits, BCLK:out, WCLK:out
			LJF_32_SLAVE  = 0b11110000,	///< LJF/16Bits, BCLK:inp, WCLK:inp
			LJF_32_MASTER = 0b11111100,	///< LJF/16Bits, BCLK:out, WCLK:out
		};


#if 0
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  サンプリング周期型
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class FRQ : uint8_t {
			FS44_1,		///< 44.1 KHz
			FS48_0,		///< 48.0 KHz
			FS96_0,		///< 96.0 KHz
		};
#endif


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  アナログ入力選択型
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class INSEL : uint8_t {
			IN1L,		///< IN1L(P) SINGLE-ENDED (Left or Right)
			IN2L,		///< IN2L(P) SINGLE-ENDED for Left only
			IN2R,		///< IN2R(P) SINGLE-ENDED for Right only
			IN3L,		///< IN3L(M) SINGLE-ENDED for Left only
			IN3R,		///< IN3R(M) SINGLE-ENDED for Right only
			IN1R,		///< IN1R(M) SINGLE-ENDED (Left or Right)
			IN1L_1R,	///< IN1L(P)/IN1R(M) DIFFERENTIAL (Left or Right)
			IN2L_3L,	///< IN2L(P)/IN3L(M) DIFFERENTIAL (Left or Right)
			IN2R_3R,	///< IN2R(P)/IN3R(M) DIFFERENTIAL (Left or Right)
		};


		static const uint8_t PAGE_CTRL = 0x00;  ///< PAGE CTRL command

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  ページ（０）・マップ型
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class CMD_PAGE0 : uint8_t {
			PAGE_CTRL,				///< Page control register
			SW_RESET,				///< S/W RESET

			CLOCK_GEN = 4,			///< Clock-gen multiplexing
			PLL_P_R,				///< PLL P and R-VAL
			PLL_J,					///< PLL J-VAL
			PLL_D_MSB,				///< PLL D-VAL MSB
			PLL_D_LSB,				///< PLL D-VAL LSB

			ADC_NADC = 18,			///< ADC NADC (0x12)
			ADC_MADC,				///< ADC MADC
			ADC_AOSR,				///< ADC AOSR
			ADC_IADC,				///< ADC IADC
			ADC_DSP,				///< ADC miniDSP engine decimation

			CLKOUT_MUX = 25,		///< CLKOUT MUX (0x19)
			CLKOUT_M_DIV,			///< CLKOUT M Divider
			ADC_AIFC,				///< ADC audio interface control 1
			CH_OFFSET_1,			///< Data slot offset programmabillity 1 (Ch_Offset_1)
			ADC_IFC_2,				///< ADC interface control 2
			BCLK_N_DIV,				///< BCLK N Divider
			S_AIFC_1,				///< Secondary audio interface control 1
			S_AIFC_2,				///< Secondary audio interface control 2
			S_AIFC_3,				///< Secondary audio interface control 3
			I2S_SYNC,				///< I^2S sync

			ADC_FLAG = 36,			///< ADC flag register
			CH_OFFSET_2,			///< Data slot offset programmabillity 2 (Ch_Offset_2)
			I2S_TDM,				///< I^2S TDM control register

			INTR_FLAG_1 = 42,  		///< Interrupt flags (overflow)
			INTR_FLAG_2,	  		///< Interrupt flags (overflow)

			INTR_FLAG_ADC_1 = 45,	///< Interrupt flags-ADC

			INTR_FLAG_ADC_2 = 47,	///< Interrupt flags-ADC
			INT1_CTRL,				///< INT1 interrupt control
			INT2_CTRL,				///< INT2 interrupt control

			DMCLK_GPIO2 = 51,		///< DMCLK/GPIO2 control
			DMDIN_GPIO1,			///< DMDIN/GPIO1 control
			DOUT,					///< DOUT (out pin) control

			ADC_SYNC_1 = 57,		///< ADC sync control 1
			ADC_SYNC_2,				///< ADC sync control 2
			ADC_CIC_FILTER,			///< ADC CIC filter gain control

			ADC_PROC = 61,			///< ADC processing block selection
			PROG_INST,				///< Programmable instruction mode control bits

			DMIC_PLARITY = 80,		///< Digital microphone polarity control
			ADC_DIGITAL,			///< ADC digital
			ADC_FINE_VOLUME,		///< ADC fine volume control
			LEFT_ADC_VOLUME,		///< Left ADC volume control
			RIGHT_ADC_VOLUME,		///< Right ADC volume control
			ADC_PHASE,				///< ADC phase compensation
			LEFT_AGC_CTRL_1,		///< Left AGC control 1
			LEFT_AGC_CTRL_2,		///< Left AGC control 2
			LEFT_AGC_MAX_GAIN,		///< Left AGC maximum gain
			LEFT_AGC_ATTACK_TIME,	///< Left AGC attack time
			LEFT_AGC_DECAY_TIME,	///< Left AGC decay time
			LEFT_AGC_NOISE_DEBOUNCE,	///< Left AGC noise debounce
			LEFT_AGC_SIGNAL_DEBOUNCE,	///< Left AGC signal debounce
			LEFT_AGC_GAIN,			///< Left AGC gain
			RIGHT_AGC_CTRL_1,		///< Right AGC control 1
			RIGHT_AGC_CTRL_2,		///< Right AGC control 2
			RIGHT_AGC_MAX_GAIN,		///< Right AGC maximum gain
			RIGHT_AGC_ATTACK_TIME,	///< Right AGC attack time
			RIGHT_AGC_DECAY_TIME,	///< Right AGC decay time
			RIGHT_AGC_NOISE_DEBOUNCE,	///< Right AGC noise debounce
			RIGHT_AGC_SIGNAL_DEBOUNCE,	///< Right AGC signal debounce
			RIGHT_AGC_GAIN,			///< Right AGC gain
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  ページ１・マップ型
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class CMD_PAGE1 : uint8_t {
			PAGE_CTRL,				///< Page control register

			DITHER_CTRL = 26,		///< Dither control

			MICBIAS_CTRL = 51,		///< 51 MICBIAS control
			LEFT_INPSEL_1 = 52,		///< 52 Left ADC input selection for left PGA

			LEFT_INPSEL_2 = 54,		///< 54 Left ADC input selection for left PGA
			RIGHT_INPSEL_1 = 55,	///< 55 Right ADC input selection for right PGA

			RIGHT_INPSEL_2 = 57,	///< 57 Right ADC input selection for right PGA

			LEFT_ANALOG = 59,		///< 59 Left analog PGA setting
			RIGHT_ANALOG,			///< 60 Right analog PGA setting
			ADC_LOW_CUR_MODE,		///< 61 ADC low-current modes
			ADC_ANALOG_FLAGS,		///< 62 ADC analog PGA flags
		};

	private:

		I2C_IO&		i2c_io_;

		uint8_t		cur_page_;

		bool read_(uint8_t cmd, uint8_t& data)
		{
			uint8_t tmp[2];
			tmp[0] = cmd;
			if(!i2c_io_.send(DEV_ADR, tmp, 1)) {
				return false;
			}
			tmp[0] = 0;
			tmp[1] = 0;
			if(!i2c_io_.recv(DEV_ADR, tmp, 2)) {
				return false;
			}
			data = tmp[1];
			return true;
		}


		bool write_(uint8_t cmd, uint8_t data)
		{
			uint8_t tmp[2];
			tmp[0] = cmd;
			tmp[1] = data;
			return i2c_io_.send(DEV_ADR, tmp, 2);
		}


		bool set_page_(uint8_t page)
		{
			bool ret = true;
			if(cur_page_ != page) {
				ret = write_(PAGE_CTRL, page);
				if(ret) {
					cur_page_ = page;
				}
			}
			return ret;
		}


		bool set_(CMD_PAGE0 cmd, uint8_t data)
		{
			if(!set_page_(0x00)) {
				return false;
			}
			return write_(static_cast<uint8_t>(cmd), data);
		}


		bool get_(CMD_PAGE0 cmd, uint8_t& data)
		{
			if(!set_page_(0x00)) {
				return false;
			}
			return read_(static_cast<uint8_t>(cmd), data);
		}


		bool set_(CMD_PAGE1 cmd, uint8_t data)
		{
			if(!set_page_(0x01)) {
				return false;
			}
			return write_(static_cast<uint8_t>(cmd), data);
		}


		bool select_inputs_(INSEL insel, CMD_PAGE1 reg1, CMD_PAGE1 reg2)
		{
			switch(insel) {
			case INSEL::IN1L:     // IN1L(P) SINGLE-ENDED (Left or Right)

				break;
			case INSEL::IN2L:     // IN2L(P) SINGLE-ENDED for Left only

				break;
			case INSEL::IN2R:     // IN2R(P) SINGLE-ENDED for Right only

				break;
			case INSEL::IN3L:     // IN3L(M) SINGLE-ENDED for Left only

				break;
			case INSEL::IN3R:     // IN3R(M) SINGLE-ENDED for Right only

				break;
			case INSEL::IN1R:     // IN1R(M) SINGLE-ENDED (Left or Right)

				break;
			case INSEL::IN1L_1R:  // IN1L(P)/IN1R(M) DIFFERENTIAL (Left or Right)

				break;
			case INSEL::IN2L_3L:  // IN2L(P)/IN3L(M) DIFFERENTIAL (Left or Right)

				break;
			case INSEL::IN2R_3R:  // IN2R(P)/IN3R(M) DIFFERENTIAL (Left or Right)

				break;
			default:
				return false;
			}
			return true;
		}

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief	コンストラクター
			@param[in]	i2c	iica_io クラスを参照で渡す
		 */
		//-----------------------------------------------------------------//
		TLV320ADC3001(I2C_IO& i2c) : i2c_io_(i2c), cur_page_(0xff) { }


		//-----------------------------------------------------------------//
		/*!
			@brief	開始
			@param[in]	left	Left  チャネル選択
			@param[in]	right	Right チャネル選択
			@param[in]	inf		インターフェース
//			@param[in]	frq		サンプリング周期
			@return エラーなら「false」を返す
		 */
		//-----------------------------------------------------------------//
//		bool start(INSEL left, INSEL right, INF inf, FRQ frq)
		bool start(INSEL left, INSEL right, INF inf)
		{
			if(!set_(CMD_PAGE0::SW_RESET, 1)) {
				return false;
			}

			bool f;
			if((static_cast<uint8_t>(inf) & 0b00001100) == 0) {  // slave (BCLK, WCLK input)
				// BCLK: MCLK / 4 (TI sample)
				// BCLK: MCLK / 8
				// WCLK: MCLK / 256
				f = set_(CMD_PAGE0::CLOCK_GEN, 0b00000000);
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_P_R,   0b00010001);
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_J,     0b00000100);
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_D_MSB, 0b00000000);
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_D_LSB, 0b00000000);

				// (b) Power up PLL (if PLL is necessary) - Not Used in this Example
				f = set_(CMD_PAGE0::PLL_P_R,   0b00010001); 
				if(!f) return false;
			} else {
				f = set_(CMD_PAGE0::CLOCK_GEN, 0b00000000);  // PLL_CLKIN = MCLK, CODEC_CLKIN = MCLK 
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_P_R,   0b10010001);  // PLL is powered up, PLL divide = 2, PLL multiplier = 1
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_J,     0b00000100);  // PLL multiplier J = 4
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_D_MSB, 0b00000000);  // PLL fractional multiplier MSB(B0 to B5)
				if(!f) return false;
				f = set_(CMD_PAGE0::PLL_D_LSB, 0b00000000);  // PLL fractional multiplier LSB(B0 to B7)
				if(!f) return false;

//				set_(CMD_PAGE0::CLKOUT_MUX, 0b00000011);
				f = set_(CMD_PAGE0::BCLK_N_DIV, 0b10000100);  // BCLK N Divider
				if(!f) return false;

				// (b) Power up PLL (if PLL is necessary) - Not Used in this Example
				f = set_(CMD_PAGE0::PLL_P_R,   0b10010001); 
				if(!f) return false;
			}

			// 最終的なサンプリング周期：ADC_FS
			// Figure 28. 参照
			// CLOCK_GEN: で CODEC_CLKIN: MCLK 
			// ADC_FS = MCLK / NADC / MADC / AOSR
			// ※ 384FS
			// NADC = 1, divider powered on
			f = set_(CMD_PAGE0::ADC_NADC, 0x81);
			if(!f) return false;
			// MADC = 3, divider powered on
			f = set_(CMD_PAGE0::ADC_MADC, 0x83);
			if(!f) return false;
			// AOSR = 128
			f = set_(CMD_PAGE0::ADC_AOSR, 128);
			if(!f) return false;

			// Audio Interface Control 1
			f = set_(CMD_PAGE0::ADC_AIFC, static_cast<uint8_t>(inf));
			if(!f) return false;
			// Audio Interface I2S_TDM
			// Default: 0b00000010
#ifdef BETA_VERSION
			f = set_(CMD_PAGE0::ADC_IFC_2, 0b00001010);
			if(!f) return false;
#else
			f = set_(CMD_PAGE0::I2S_TDM, 0b00000011);
			if(!f) return false;
#endif
			// PRB_P1 (0x3D, 0x01)
			f = set_(CMD_PAGE0::ADC_PROC, 0x01);
			if(!f) return false;

			// 3. Program Analog Blocks
			// (a) Set register Page to 1 (0x00 0x01)
			// (b) Program MICBIAS if appicable
			// Not used (default) (0x33(51) 0x00)
			f = set_(CMD_PAGE1::MICBIAS_CTRL, 0x00);
			if(!f) return false;

			// (c) Program MicPGA
			// Left Analog PGA Seeting = 0dB (0x3b(59) 0x00)
			f = set_(CMD_PAGE1::LEFT_ANALOG,  0x00);
			if(!f) return false;

			// Right Analog PGA Seeting = 0dB (0x3c(60) 0x00)
			f = set_(CMD_PAGE1::RIGHT_ANALOG, 0x00);
			if(!f) return false;

			// (d) Routing of inputs/common mode to ADC input
			// (e) Unmute analog PGAs and set analog gain
			// Left  ADC Input selection for Left PGA  = IN2R(P), IN3R(M)
			f = select_inputs_(left,  CMD_PAGE1::LEFT_INPSEL_1,  CMD_PAGE1::LEFT_INPSEL_2);
///			f = set_(CMD_PAGE1::LEFT_INPSEL_2,  0b10110011);
			f = set_(CMD_PAGE1::LEFT_INPSEL_1,  0b11110011);
			if(!f) return false;
			// Right ADC Input selection for Right PGA = IN2R(P), IN3R(M)
			f = select_inputs_(right, CMD_PAGE1::RIGHT_INPSEL_1, CMD_PAGE1::RIGHT_INPSEL_2);
///			f = set_(CMD_PAGE1::RIGHT_INPSEL_2, 0b00111111);
			f = set_(CMD_PAGE1::RIGHT_INPSEL_1, 0b11110011);
			if(!f) return false;

			// 4. Program ADC
			// (a) Set register Page to 0
			// (b) Power up ADC channel
			// Power-up Left ADC and Right ADC (0x51 0xC2)
			f = set_(CMD_PAGE0::ADC_DIGITAL, 0b11000010);
			if(!f) return false;

			// (c) Unmute digital volume control and set gain = 0 dB
			// UNMUTE (0x52(82), 0x00)
			f = set_(CMD_PAGE0::ADC_FINE_VOLUME, 0x00);
			if(!f) return false;

			return true;
		}
	};
}
