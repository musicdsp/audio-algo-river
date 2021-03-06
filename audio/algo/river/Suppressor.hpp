/** @file
 * @author Edouard DUPIN
 * @author Fatima MARFOUQ
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>
#include <echrono/Steady.hpp>
#include <audio/format.hpp>
#include <ememory/memory.hpp>

namespace audio {
	namespace algo {
		namespace river {
			class SupressorPrivate;
			/**
			 * @brief Supressor is a simple Algo that remove data from the microphone when the speaker is active.
			*/
			class Supressor {
				public:
					/**
					 * @brief Constructor
					 */
					Supressor();
					/**
					 * @brief Destructor
					 */
					virtual ~Supressor();
				public:
					/**
					 * @brief Reset algorithm
					 */
					virtual void reset();
					/**
					 * @brief Initialize the Algorithm
					 * @param[in] _nbChannel Number of channel in the stream.
					 * @param[in] _sampleRate Sample rate.
					 * @param[in] _format Input/output data format.
					 */
					virtual void init(int8_t _nbChannel, float _sampleRate, enum audio::format _format = audio::format_float);
					/**
					 * @brief Get list of format suported in input.
					 * @return list of supported format
					 */
					virtual etk::Vector<enum audio::format> getSupportedFormat();
					/**
					 * @brief Get list of algorithm format suported. No format convertion.
					 * @return list of supported format
					 */
					virtual etk::Vector<enum audio::format> getNativeSupportedFormat();
					/**
					 * @brief Main input algo process.
					 * @param[in,out] _output Output data.
					 * @param[in] _input Input data.
					 * @param[in] _inputFeedback Input feedback data (all time MONO).
					 * @param[in] _nbChunk Number of chunk in the input buffer.
					 * @param[in] _nbChannel Number of channel in the stream.
					 */
					virtual void process(void* _output, const void* _input, const void* _inputFeedback, size_t _nbChunk);
				protected:
					ememory::SharedPtr<SupressorPrivate> m_private; // private data.
				public: // parameter area:
					/**
					 * @brief Set the algo attaque time.
					 * @param[in] _time Time of the attaque gain.
					 */
					virtual void setAttaqueTime(echrono::microseconds _time);
					/**
					 * @brief Set the algo release time.
					 * @param[in] _time Time of the release gain.
					 */
					virtual void setReleaseTime(echrono::microseconds _time);
					/**
					 * @brief Set the minimum Gain.
					 * @param[in] _gain dB gain to apply for minimum.
					 */
					virtual void setMinimumGain(float _gain);
					/**
					 * @brief Set the threashold Gain.
					 * @param[in] _gain dB gain to start removing data.
					 */
					virtual void setThreshold(float _gain);
					/**
					 * @brief Set the delay befor releasing time.
					 * @param[in] _time Time of the dalay release.
					 */
					virtual void setReleaseDelay(echrono::microseconds _time);
			};
		}
	}
}

