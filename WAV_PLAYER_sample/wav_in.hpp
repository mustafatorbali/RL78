//=====================================================================//
/*!	@file
	@brief	WAV 音声ファイルを扱うクラス
	@author	平松邦仁 (hira@rvf-rc45.net)
*/
//=====================================================================//
#include <cstring>
#include "ff12a/src/ff.h"

namespace audio {

	//-----------------------------------------------------------------//
	/*!
		@brief	WAV 形式ファイルクラス
	*/
	//-----------------------------------------------------------------//
	class wav_in {

		struct WAVEFILEHEADER {
			char	   	szRIFF[4];
			uint32_t	ulRIFFSize;
			char	   	szWAVE[4];
		};

		struct RIFFCHUNK {
			char   		szChunkName[4];
			uint32_t	ulChunkSize;
		};

		struct WAVEFMT {
			uint16_t	usFormatTag;
			uint16_t	usChannels;
			uint32_t	ulSamplesPerSec;
			uint32_t	ulAvgBytesPerSec;
			uint16_t	usBlockAlign;
			uint16_t	usBitsPerSample;
			uint16_t	usSize;
			uint16_t	usReserved;
			uint32_t	ulChannelMask;
			uint32_t	guidSubFormat;
		};

		uint32_t	data_top_;
		uint32_t	data_size_;

		uint32_t	rate_;
		uint8_t		chanel_;
		uint8_t		bits_;

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief	コンストラクター
		*/
		//-----------------------------------------------------------------//
		wav_in() : data_top_(0), data_size_(0), rate_(0), chanel_(0), bits_(0) { }


		//-----------------------------------------------------------------//
		/*!
			@brief	ヘッダーをロードして、フォーマット、サイズを取得する
			@param[in]	path	ファイル・パス
		*/
		//-----------------------------------------------------------------//
		bool load_header(FIL* fil)
		{
			uint32_t ofs = 0;
			{
				WAVEFILEHEADER wh;
				UINT br;
				if(f_read(fil, &wh, sizeof(wh), &br) != FR_OK) {
					return false;
				}
				if(br != sizeof(wh)) return false;
				if(std::strncmp(wh.szRIFF, "RIFF", 4) == 0 && std::strncmp(wh.szWAVE, "WAVE", 4) == 0) ;
				else return false;
				ofs += sizeof(wh);
			}

			while(1) {
				RIFFCHUNK rc;
				UINT br;
				if(f_read(fil, &rc, sizeof(rc), &br) != FR_OK) {
					return false;
				}
				if(br != sizeof(rc)) return false;
				ofs += sizeof(rc);

				if(std::strncmp(rc.szChunkName, "fmt ", 4) == 0) {
					WAVEFMT wf;
					if(f_read(fil, &wf, sizeof(wf), &br) != FR_OK) {
						return false;
					}
					if(br != sizeof(wf)) return false;
					rate_ = wf.ulSamplesPerSec;
					chanel_ = wf.usChannels;
					bits_ = wf.usBitsPerSample;
				} else if(std::strncmp(rc.szChunkName, "data", 4) == 0) {
					data_size_ = rc.ulChunkSize;
					break;
				}
				ofs += rc.ulChunkSize;
				f_lseek(fil, ofs);
			}
			data_top_ = f_tell(fil);

			return true;
		}

		//-----------------------------------------------------------------//
		/*!
			@brief	データ先頭のファイル位置を返す
			@return ファイル位置
		*/
		//-----------------------------------------------------------------//
		uint32_t get_top() const { return data_top_; }


		//-----------------------------------------------------------------//
		/*!
			@brief	データサイズを取得
			@return データサイズ
		*/
		//-----------------------------------------------------------------//
		uint32_t get_size() const { return data_size_; }


		//-----------------------------------------------------------------//
		/*!
			@brief	サンプルレートを取得
			@return サンプルレート
		*/
		//-----------------------------------------------------------------//
		uint32_t get_rate() const { return rate_; }


		//-----------------------------------------------------------------//
		/*!
			@brief	チャネル数を取得
			@return チャネル数
		*/
		//-----------------------------------------------------------------//
		uint8_t get_chanel() const { return chanel_; }


		//-----------------------------------------------------------------//
		/*!
			@brief	量子化数を取得
			@return 量子化数
		*/
		//-----------------------------------------------------------------//
		uint8_t get_bits() const { return  bits_; }
	};
}
