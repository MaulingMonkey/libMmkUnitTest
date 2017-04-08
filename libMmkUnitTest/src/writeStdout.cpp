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

#include <mmk/test/unit/writeStdout.hpp>
#include <mmk/test/unit/testDescription.hpp>
#include <cstdio>

namespace mmk { namespace test { namespace unit {
	void writeStdout::onBeginCategory(const categoryEvent& event) { printf("%s\n", event.category ? event.category : "(no category)"); }
	void writeStdout::onEndCategory  (const categoryEvent&      ) { printf("\n"); }
	void writeStdout::onBeginTest    (const testEvent&     event) { if (event.test->title) printf("  - %s\n", event.test->title); }
	void writeStdout::onEndCheck     (const checkEvent&    event) { printf("    [%s] %s\n", event.result == checkResultPass ? "pass" :  event.result == checkResultFail ? "FAIL" : "... ", event.message ? event.message : ""); }
}}} // namespace mmk::test::unit
