/* Copyright 2017 MaulingMonkey

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef ZMMK_TEST_UNIT_SETTINGS_HPP
#define ZMMK_TEST_UNIT_SETTINGS_HPP

#include "listeners.hpp"

namespace mmk { namespace test { namespace unit {
	struct settings {
		unit::listeners listeners;
		// ...
	};
}}} // namespace mmk::test::unit

#endif /* ndef ZMMK_TEST_UNIT_SETTINGS_HPP */