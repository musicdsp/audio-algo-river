/** @file
 * @author Edouard DUPIN
 * @author Fatima MARFOUQ
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>

namespace audio {
	namespace algo {
		namespace river {
			float convolution(float* _dataMinus, float* _dataPlus, size_t _count);
		}
	}
}

