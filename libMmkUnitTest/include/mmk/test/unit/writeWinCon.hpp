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

#ifndef ZMMK_TEST_UNIT_WRITE_WINCON_HPP
#define ZMMK_TEST_UNIT_WRITE_WINCON_HPP
#ifdef _MSC_VER

#include "listener.hpp"
#include "testDescription.hpp"
#include <cstdio>
#define NOMINMAX
#include <windows.h>

namespace mmk { namespace test { namespace unit {
	class writeWinCon : public listener {
	private:
		const HANDLE hConsole;

	public:
		writeWinCon(HANDLE hConsole): hConsole(hConsole) {}
		~writeWinCon() {}

		void onBeginCategory(const categoryEvent& event) override {
			if (!hConsole) return;
			const WORD header = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
			const WORD body   = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
			SetConsoleTextAttribute(hConsole, header);
			printf("%s", event.category ? event.category : "(no category)");
			SetConsoleTextAttribute(hConsole, body);
			printf("\n");
		}
		void onEndCategory(const categoryEvent&       ) override { printf("\n"); }
		void onBeginTest  (const testEvent&      event) override { printf("  - %s\n", event.test->title ? event.test->title : event.test->id ? event.test->id : "<unknown test>"); }
		void onBeginCheck (const checkEvent&     event) override { onCheck(event); }
		void onEndCheck   (const checkEvent&     event) override { onCheck(event); printf("                 \n"); }

		void onCheck(const checkEvent&     event) {
			const WORD icon   = (event.result == checkResultPass ? FOREGROUND_GREEN : event.result == checkResultFail ? FOREGROUND_RED : (FOREGROUND_GREEN | FOREGROUND_RED)) | FOREGROUND_INTENSITY;
			const WORD body   = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;

			CONSOLE_SCREEN_BUFFER_INFO info = {};
			if (GetConsoleScreenBufferInfo(hConsole, &info)) {
				COORD newCoord = {};
				newCoord.Y = info.dwCursorPosition.Y;
				SetConsoleCursorPosition(hConsole, newCoord);
			}
			printf("    ");
			SetConsoleTextAttribute(hConsole, icon);
			printf("%s", event.result == checkResultPass ? "O" : event.result == checkResultFail ? "X" : "?");
			SetConsoleTextAttribute(hConsole, body);
			printf(" %s", event.message ? event.message : "");
		}
	};
}}} // namespace mmk::test::unit

#endif /* def _MSC_VER */
#endif /* ndef ZMMK_TEST_UNIT_WRITE_WINCON_HPP */
