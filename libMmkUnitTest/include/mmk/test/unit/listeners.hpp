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

#ifndef ZMMK_TEST_UNIT_LISTENERS_HPP
#define ZMMK_TEST_UNIT_LISTENERS_HPP

#include "listener.hpp"
#include <vector>

namespace mmk { namespace test { namespace unit {
	struct listeners : std::vector<listener*>, listener {
		virtual void onBeginCategory(const categoryEvent& event) override { for (auto* l : *this) l->onBeginCategory(event); }
		virtual void onEndCategory  (const categoryEvent& event) override { for (auto* l : *this) l->onEndCategory  (event); }
		virtual void onBeginTest    (const testEvent&     event) override { for (auto* l : *this) l->onBeginTest    (event); }
		virtual void onEndTest      (const testEvent&     event) override { for (auto* l : *this) l->onEndTest      (event); }
		virtual void onBeginCheck   (const checkEvent&    event) override { for (auto* l : *this) l->onBeginCheck   (event); }
		virtual void onEndCheck     (const checkEvent&    event) override { for (auto* l : *this) l->onEndCheck     (event); }
	};
}}} // namespace mmk::test::unit

#endif /* ndef ZMMK_TEST_UNIT_LISTENERS_HPP */
