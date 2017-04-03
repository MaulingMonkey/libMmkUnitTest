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

#ifndef ZMMK_TEST_UNIT_LISTENER_HPP
#define ZMMK_TEST_UNIT_LISTENER_HPP

#include "checkResult.hpp"
#include <cstdarg>

namespace mmk { namespace test { namespace unit {
	struct testDescription;

	struct listener {
		struct categoryEvent { const char* category; };
		struct testEvent     { const testDescription* test; };
		struct checkEvent    { checkResult result; const char* message; };

		virtual ~listener() {}
		virtual void onBeginCategory(const categoryEvent& event) { (void)event; }
		virtual void onEndCategory  (const categoryEvent& event) { (void)event; }
		virtual void onBeginTest    (const testEvent&     event) { (void)event; }
		virtual void onEndTest      (const testEvent&     event) { (void)event; }
		virtual void onBeginCheck   (const checkEvent&    event) { (void)event; }
		virtual void onEndCheck     (const checkEvent&    event) = 0;
	};
}}} // namespace mmk::test::unit

#endif /* ndef ZMMK_TEST_UNIT_LISTENER_HPP */
