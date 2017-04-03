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

#include "testList.hpp"
#include <cassert>

namespace mmk { namespace test { namespace unit {
	namespace { testList* gList; }

	testList* testList::get() {
		static testList utdl;
		return gList; // returns null once cleaned up
	}

	testList::testList()  { assert(gList == 0); gList = this; }
	testList::~testList() { assert(gList == this); gList = 0; }

}}} // namespace mmk::test::unit
