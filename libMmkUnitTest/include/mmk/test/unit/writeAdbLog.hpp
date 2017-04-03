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

#ifndef ZMMK_TEST_UNIT_WRITE_ADBLOG_HPP
#define ZMMK_TEST_UNIT_WRITE_ADBLOG_HPP
#ifdef __ANDROID__

#include "listener.hpp"
#include "testDescription.hpp"
#include <android/log.h>

namespace mmk { namespace test { namespace unit {
	class writeAdbLog : public listener {
	private:
		const char* const tag;

	public:
		writeAdbLog():                tag("libMmkUnitTest")             {}
		writeAdbLog(const char* tag): tag(tag ? tag : "libMmkUnitTest") {}

		void onBeginCategory(const categoryEvent& event) override { __android_log_print(ANDROID_LOG_DEBUG, tag, "%s", event.category ? event.category : "(no category)"); }
		void onEndCategory  (const categoryEvent&      ) override { __android_log_print(ANDROID_LOG_DEBUG, tag, ""); }
		void onBeginTest    (const testEvent&     event) override { __android_log_print(ANDROID_LOG_VERBOSE, tag, "  - %s", !event.test ? "<no test>" : event.test->title ? event.test->title : event.test->id ? event.test->id : "<unknown test>"); }
		void onEndCheck     (const checkEvent&    event) override { __android_log_print(toPrio(event.result), tag, "    %s", event.message ? event.message : ""); }

		int toPrio(checkResult r) {
			switch (r) {
			case checkResultBegin: return ANDROID_LOG_WARN;
			case checkResultPass:  return ANDROID_LOG_INFO;
			case checkResultFail:  return ANDROID_LOG_ERROR;
			}
			return ANDROID_LOG_WARN;
		}
	};
}}} // namespace mmk::test::unit

#endif /* def __ANDROID__ */
#endif /* ndef ZMMK_TEST_UNIT_WRITE_ADBLOG_HPP */
