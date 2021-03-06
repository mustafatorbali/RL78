#pragma once
//=====================================================================//
/*!	@file
	@brief	RL78/L1C グループ・タイマ・アレイ・ユニット定義
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2017 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RL78/blob/master/LICENSE
*/
//=====================================================================//
#include "common/io_utils.hpp"
#include "L1C/peripheral.hpp"

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  タイマ・アレイ・ユニット・テンプレート
		@param[in]	PER		ペリフェラル型
		@param[in]	UOFS	ユニット・オフセット（0x00、0x40）
		@param[in]	CHOFS	チャネル・オフセット（0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E)
		@param[in]	DRADR	データレジスタ・アドレス
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <peripheral PER, uint32_t UOFS, uint32_t CHOFS, uint32_t DRADR>
	struct tau_t {

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・カウンタ・レジスタ（TCR）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static ro16_t<0xF0180 + UOFS + CHOFS> TCR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・データ・レジスタ（TDR）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static rw16_t<DRADR> TDR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・データ・レジスタ・下位バイト（TDRL）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static rw8_t<DRADR> TDRL;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・データ・レジスタ・上位バイト（TDRH）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static rw8_t<DRADR + 1> TDRH;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・クロック選択レジスタ（TPS）テンプレート @n
					※ユニット単位
			@param[in]	T	アクセス・クラス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <class T>
		struct tps_t : public T {
			using T::operator =;
			using T::operator ();
			using T::operator |=;
			using T::operator &=;

			bits_rw_t<T, bitpos::B0,  4>	PRS0;
			bits_rw_t<T, bitpos::B4,  4>	PRS1;
			bits_rw_t<T, bitpos::B8,  2>	PRS2;
			bits_rw_t<T, bitpos::B12, 2>	PRS3;
		};
		static tps_t< rw16_t<0xF01B6 + UOFS> > TPS;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・モード・レジスタ（TMR）テンプレート
			@param[in]	T	アクセス・クラス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <class T>
		struct tmr_t : public T {
			using T::operator =;
			using T::operator ();
			using T::operator |=;
			using T::operator &=;

			bit_rw_t<T, bitpos::B0>	 	 MD0;
			bits_rw_t<T, bitpos::B1, 3>	 MD;
			bits_rw_t<T, bitpos::B6, 2>	 CIS;
			bits_rw_t<T, bitpos::B8, 3>	 STS;

			bit_rw_t<T, bitpos::B11>	 MAS;  ///< Master chanel: 2, 4, 6

			bit_rw_t<T, bitpos::B11>	 SPLIT;  ///< Split: 1, 3

			bit_rw_t<T, bitpos::B12>	 CCS;
			bits_rw_t<T, bitpos::B14, 3> CKS;
		};
		static tmr_t< rw16_t<0xF0190 + UOFS + CHOFS> > TMR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・ステータス・レジスタ（TSR）テンプレート
			@param[in]	T	アクセス・クラス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <class T>
		struct tsr_t : public T {
			using T::operator =;
			using T::operator ();
			using T::operator |=;
			using T::operator &=;

			bit_rw_t<T, bitpos::B0>	 OVF;
		};
		static tsr_t< rw8_t<0xF01A0 + UOFS + CHOFS> > TSR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル許可ステータス・レジスタ（TE）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_ro_t<rw8_t<0xF01B0 + UOFS>, static_cast<bitpos>(CHOFS / 2)> TE;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル許可ステータス・レジスタ１（TEH1）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_ro_t<rw16_t<0xF01B0 + UOFS>, bitpos::B9> TEH1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル許可ステータス・レジスタ３（TEH3）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_ro_t<rw16_t<0xF01B0 + UOFS>, bitpos::B11> TEH3;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル開始レジスタ（TS）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw8_t<0xF01B2 + UOFS>, static_cast<bitpos>(CHOFS / 2)> TS;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル開始レジスタ１（TS1）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw16_t<0xF01B2 + UOFS>, bitpos::B9> TS1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル開始レジスタ３（TS3）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw16_t<0xF01B2 + UOFS>, bitpos::B11> TS3;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル停止レジスタ（TT）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw8_t<0xF01B4 + UOFS>, static_cast<bitpos>(CHOFS / 2)> TT;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル停止レジスタ１（TT1）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw16_t<0xF01B4 + UOFS>, bitpos::B9> TT1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ・チャネル停止レジスタ３（TT3）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw16_t<0xF01B4 + UOFS>, bitpos::B11> TT3;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ入力選択レジスタ（TIS）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bits_rw_t<rw8_t<0xF0074>, bitpos::B0, 3> TIS;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ出力許可レジスタ（TOE）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw8_t<0xF01BA + UOFS>, static_cast<bitpos>(CHOFS / 2)> TOE;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ出力レジスタ（TO）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw8_t<0xF01B8 + UOFS>, static_cast<bitpos>(CHOFS / 2)> TO;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ出力レベル・レジスタ（TOL）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw8_t<0xF01BC + UOFS>, static_cast<bitpos>(CHOFS / 2)> TOL;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  タイマ出力モード・レジスタ（TOM）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static bit_rw_t<rw8_t<0xF01BE + UOFS>, static_cast<bitpos>(CHOFS / 2)> TOM;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  入力切り替え制御レジスタ（ISC）テンプレート
			@param[in]	T	アクセス・クラス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <class T>
		struct isc_t : public T {
			using T::operator =;
			using T::operator ();
			using T::operator |=;
			using T::operator &=;

			bit_rw_t<T, bitpos::B0>	 ISC0;
			bit_rw_t<T, bitpos::B1>	 ISC1;
		};
		static isc_t< rw8_t<0xF0073> > ISC;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  ノイズ・フィルタ許可レジスタ（NFEN）テンプレート
			@param[in]	T	アクセス・クラス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <class T>
		struct nfen_t : public T {
			using T::operator =;
			using T::operator ();
			using T::operator |=;
			using T::operator &=;

			bit_rw_t<T, static_cast<bitpos>(CHOFS)> TNFEN;
		};
		static nfen_t< rw8_t<0xF0071 + (UOFS / 0x40)> > NFEN;


        //-----------------------------------------------------------------//
        /*!
            @brief  ユニット番号を取得
			@return 「０」又は「１」
        */
        //-----------------------------------------------------------------//
		static uint8_t get_unit_no() { return UOFS / 0x40; }


        //-----------------------------------------------------------------//
        /*!
            @brief  チャネル番号を取得
			@return 「０～７」
        */
        //-----------------------------------------------------------------//
		static uint8_t get_chanel_no() { return CHOFS / 0x02; }


		//-------------------------------------------------------------//
		/*!
			@brief  ペリフェラル種別を取得
			@return ペリフェラル種別
		*/
		//-------------------------------------------------------------//
		static peripheral get_peripheral() { return PER; }
	};
	typedef tau_t<peripheral::TAU00, 0x00, 0x00, 0xFFF18> TAU00;
	typedef tau_t<peripheral::TAU01, 0x00, 0x02, 0xFFF1A> TAU01;
	typedef tau_t<peripheral::TAU02, 0x00, 0x04, 0xFFF64> TAU02;
	typedef tau_t<peripheral::TAU03, 0x00, 0x06, 0xFFF66> TAU03;
	typedef tau_t<peripheral::TAU04, 0x00, 0x08, 0xFFF68> TAU04;
	typedef tau_t<peripheral::TAU05, 0x00, 0x0A, 0xFFF6A> TAU05;
	typedef tau_t<peripheral::TAU06, 0x00, 0x0C, 0xFFF6C> TAU06;
	typedef tau_t<peripheral::TAU07, 0x00, 0x0E, 0xFFF6E> TAU07;
}
