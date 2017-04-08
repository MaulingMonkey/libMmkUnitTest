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

#include <mmk/test/unit/writeAdbLog.hpp>
#ifdef __ANDROID__
#include <mmk/test/unit/testDescription.hpp>
#include <android/log.h>

namespace mmk { namespace test { namespace unit {
	void writeAdbLog::onBeginCategory(const categoryEvent& event) { __android_log_print(ANDROID_LOG_DEBUG, tag, "%s", event.category ? event.category : "(no category)"); }
	void writeAdbLog::onEndCategory  (const categoryEvent&      ) { __android_log_print(ANDROID_LOG_DEBUG, tag, ""); }
	void writeAdbLog::onBeginTest    (const testEvent&     event) { __android_log_print(ANDROID_LOG_VERBOSE, tag, "  - %s", !event.test ? "<no test>" : event.test->title ? event.test->title : event.test->id ? event.test->id : "<unknown test>"); }
	void writeAdbLog::onEndCheck     (const checkEvent&    event) { __android_log_print(toPrio(event.result), tag, "    %s", event.message ? event.message : ""); }

	int writeAdbLog::toPrio(checkResult r) {
		switch (r) {
		case checkResultBegin: return ANDROID_LOG_WARN;
		case checkResultPass:  return ANDROID_LOG_INFO;
		case checkResultFail:  return ANDROID_LOG_ERROR;
		}
		return ANDROID_LOG_WARN;
	}
}}} // namespace mmk::test::unit

#endif /* def __ANDROID__ */
