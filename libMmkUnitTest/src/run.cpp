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

#include <mmk/test/unit/run.hpp>
#include <mmk/test/unit/writeAdbLog.hpp>
#include <mmk/test/unit/writeExitCode.hpp>
#include <mmk/test/unit/writeStdout.hpp>
#include <mmk/test/unit/writeWinCon.hpp>
#include "testList.hpp"
#ifdef _MSC_VER
#include <windows.h>
#endif
#include <cassert>
#include <cstdio>

namespace mmk { namespace test { namespace unit {
	settings* reportSettings;
	static void addMissingDefaults(settings& s) {
#ifdef _MSC_VER
		if (s.listeners.empty()) if (const HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE)) {
			static writeWinCon defaultWtw(hCon);
			s.listeners.push_back(&defaultWtw);
		}
#endif
#ifdef __ANDROID__
		if (s.listeners.empty()) {
			static writeAdbLog defaultAtw;
			s.listeners.push_back(&defaultAtw);
		}
#endif
		if (s.listeners.empty()) {
			static writeStdout defaultStw;
			s.listeners.push_back(&defaultStw);
		}
	}

	int run(int argc, char** argv) {
		(void)argc;
		(void)argv;

		settings s = settings();
		addMissingDefaults(s);

		int exitCode = 0;
		writeExitCode wec(exitCode);
		s.listeners.push_back(&wec);

		run(s);
		return exitCode;
	}

	void run(const settings& _settings) {
		settings s = _settings;
		addMissingDefaults(s);

		assert(!reportSettings);
		reportSettings = &s;

		bool firstTest = true;
		const char* prevCategory = 0;
		if (auto testList = testList::get()) {
			for (const testDescription* test : *testList) {
				assert(test); if (!test) continue;
				const char* cat = test->category;
				if (cat != prevCategory || firstTest) {
					if (!firstTest) {
						const listener::categoryEvent endPrevCat = { prevCategory };
						s.listeners.onEndCategory(endPrevCat);
					}
					prevCategory = cat;
					const listener::categoryEvent beginCat = { cat };
					s.listeners.onBeginCategory(beginCat);
				}
				firstTest = false;

				const listener::testEvent begin = { test };
				s.listeners.onBeginTest(begin);
				(*test->callback)();
				const listener::testEvent end = { test };
				s.listeners.onEndTest(end);
			}
		}
		if (!firstTest) {
			const listener::categoryEvent endLastCat = { prevCategory };
			s.listeners.onEndCategory(endLastCat);
		}

		reportSettings = 0;
	}
	namespace internal {
		void reportCheck(checkResult r, const char* format, ...) {
			char line[1024] = "";
			va_list args;
			if (format) {
				va_start(args, format);
				vsnprintf(line, sizeof(line), format, args);
			}
			const listener::checkEvent e = { r, line };
			if (r == checkResultBegin) reportSettings->listeners.onBeginCheck(e);
			else                       reportSettings->listeners.onEndCheck  (e);
			if (format) {
				va_end(args);
			}
		}
	} // namespace internal
}}} // namespace mmk::test::unit
