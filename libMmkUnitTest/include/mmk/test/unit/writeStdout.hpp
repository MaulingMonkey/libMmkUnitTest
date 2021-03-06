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

#ifndef ZMMK_TEST_UNIT_WRITE_STDOUT_HPP
#define ZMMK_TEST_UNIT_WRITE_STDOUT_HPP

#include "listener.hpp"

namespace mmk { namespace test { namespace unit {
	struct writeStdout : listener {
		void onBeginCategory(const categoryEvent& event) override;
		void onEndCategory  (const categoryEvent&      ) override;
		void onBeginTest    (const testEvent&     event) override;
		void onEndCheck     (const checkEvent&    event) override;
	};
}}} // namespace mmk::test::unit

#endif /* ndef ZMMK_TEST_UNIT_WRITE_STDOUT_HPP */
