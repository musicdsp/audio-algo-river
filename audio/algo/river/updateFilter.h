/** @file
 * @author Edouard DUPIN
 * @author Fatima MARFOUQ
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_ALGO_RIVER_UPDATE_FILTER_H__
#define __AUDIO_ALGO_RIVER_UPDATE_FILTER_H__

#include <etk/types.h>

namespace audio {
	namespace algo {
		namespace river {
			void updateFilter(float* _filter, float* _data, float _value, int32_t _count);
		}
	}
}

#endif