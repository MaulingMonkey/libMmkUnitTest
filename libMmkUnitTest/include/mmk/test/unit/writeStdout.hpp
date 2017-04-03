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
#include "testDescription.hpp"
#include <cstdio>

namespace mmk { namespace test { namespace unit {
	struct writeStdout : listener {
		void onBeginCategory(const categoryEvent& event) override { printf("%s\n", event.category ? event.category : "(no category)"); }
		void onEndCategory  (const categoryEvent&      ) override { printf("\n"); }
		void onBeginTest    (const testEvent&     event) override { if (event.test->title) printf("  - %s\n", event.test->title); }
		void onEndCheck     (const checkEvent&    event) override { printf("    [%s] %s\n", event.result == checkResultPass ? "pass" :  event.result == checkResultFail ? "FAIL" : "... ", event.message ? event.message : ""); }
	};
}}} // namespace mmk::test::unit

#endif /* ndef ZMMK_TEST_UNIT_WRITE_STDOUT_HPP */
