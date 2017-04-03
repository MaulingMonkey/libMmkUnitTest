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

#ifndef ZMMK_TEST_UNIT_TESTS_HPP
#define ZMMK_TEST_UNIT_TESTS_HPP

#include "testDescription.hpp"

// Test fixture macros
#define MMK_UNIT_TEST(title)           ZMMK_TEST_UNIT_IMPL_GLOBAL_UNIT_TEST(         ZMMK_TEST_UNIT_CONCAT(zmmk_UnitTest_,__COUNTER__), title)
#define MMK_UNIT_TEST_CATEGORY(title)  ZMMK_TEST_UNIT_IMPL_GLOBAL_UNIT_TEST_CATEGORY(ZMMK_TEST_UNIT_CONCAT(zmmk_UnitTestCategory_,__COUNTER__), title)

#ifndef MMK_UNIT_TEST_NO_SHORTHAND
	// Drop MMK_ prefix
	#define UNIT_TEST           MMK_UNIT_TEST
	#define UNIT_TEST_CATEGORY  MMK_UNIT_TEST_CATEGORY
#endif



// Implementation details
#define ZMMK_TEST_UNIT_CONCAT_2(a,b) a ## b
#define ZMMK_TEST_UNIT_CONCAT(a,b) ZMMK_TEST_UNIT_CONCAT_2(a,b)

#define ZMMK_TEST_UNIT_IMPL_GLOBAL_UNIT_TEST(id, title)                                                                                                           \
    static void id();                                                                                                                                             \
    const ::mmk::test::unit::testDescription                 ZMMK_TEST_UNIT_CONCAT(zmmk_test_desc_,id) { &id, zmmkTestCategory, #id, title, __FILE__, __LINE__ }; \
    const ::mmk::test::unit::internal::autoRegisterUnitTest  ZMMK_TEST_UNIT_CONCAT(zmmk_test_arut_,id) ( ZMMK_TEST_UNIT_CONCAT(zmmk_test_desc_,id) );             \
    static void id() /* { ... } */

#define ZMMK_TEST_UNIT_IMPL_GLOBAL_UNIT_TEST_CATEGORY(id, title)                 \
    namespace id { namespace { const char* const zmmkTestCategory = title; } } \
    namespace id /* { ... } */

namespace { const char* const zmmkTestCategory = 0; }

namespace mmk { namespace test { namespace unit {
	struct testDescription;
	namespace internal { struct autoRegisterUnitTest { autoRegisterUnitTest(const testDescription& desc); }; }
}}} // namespace mmk::test::unit

#endif /* ndef ZMMK_TEST_UNIT_TESTS_HPP */
