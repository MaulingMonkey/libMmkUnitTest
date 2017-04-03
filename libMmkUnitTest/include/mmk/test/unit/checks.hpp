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

#ifndef ZMMK_TEST_UNIT_CHECKS_HPP
#define ZMMK_TEST_UNIT_CHECKS_HPP

#include "checkResult.hpp"
#ifdef _MSC_VER
#include <windows.h> // IsDebuggerPresent, DebugBreak
#endif

#define MMK_UNIT_TEST_ASSERT_FMT(condition, format, ...)       ZMMK_UNIT_TEST_WARN_PUSH_FMT() (void)((ZMMK_UNIT_TEST_BEGIN_FMT("ASSERT_FMT(%s, ...): " format,         #condition,   __VA_ARGS__),(condition))   ? (ZMMK_UNIT_TEST_PASS_FMT("ASSERT_FMT(%s, ...): " format,         #condition,   __VA_ARGS__),0) : (ZMMK_UNIT_TEST_FAIL_FMT("ASSERT_FMT(%s, ...): " format,         #condition,   __VA_ARGS__),0)) ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_ASSERT_MSG(condition, message)           ZMMK_UNIT_TEST_WARN_PUSH_FMT() (void)((ZMMK_UNIT_TEST_BEGIN_FMT("ASSERT_MSG(%s, ...): %s",              #condition,   message    ),(condition))   ? (ZMMK_UNIT_TEST_PASS_FMT("ASSERT_MSG(%s, ...): %s",              #condition,   message    ),0) : (ZMMK_UNIT_TEST_FAIL_FMT("ASSERT_MSG(%s, ...): %s",              #condition,   message    ),0)) ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_ASSERT(condition)                        ZMMK_UNIT_TEST_WARN_PUSH_FMT() (void)((ZMMK_UNIT_TEST_BEGIN_FMT("ASSERT(%s): ...",                      #condition               ),(condition))   ? (ZMMK_UNIT_TEST_PASS_FMT("ASSERT(%s): Passed",                   #condition               ),0) : (ZMMK_UNIT_TEST_FAIL_FMT("ASSERT_(%s): Failed",                  #condition               ),0)) ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_ASSERT_CMP_FMT(a, cmp, b, format, ...)   ZMMK_UNIT_TEST_WARN_PUSH_FMT() (void)((ZMMK_UNIT_TEST_BEGIN_FMT("ASSERT_CMP_FMT(%s%s%s, ...): " format, #a, #cmp, #b, __VA_ARGS__),((a) cmp (b))) ? (ZMMK_UNIT_TEST_PASS_FMT("ASSERT_CMP_FMT(%s%s%s, ...): " format, #a, #cmp, #b, __VA_ARGS__),0) : (ZMMK_UNIT_TEST_FAIL_FMT("ASSERT_CMP_FMT(%s%s%s, ...): " format, #a, #cmp, #b, __VA_ARGS__),0)) ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_ASSERT_CMP_MSG(a, cmp, b, message)       ZMMK_UNIT_TEST_WARN_PUSH_FMT() (void)((ZMMK_UNIT_TEST_BEGIN_FMT("ASSERT_CMP_MSG(%s%s%s, ...): %s",      #a, #cmp, #b, message    ),((a) cmp (b))) ? (ZMMK_UNIT_TEST_PASS_FMT("ASSERT_CMP_MSG(%s%s%s, ...): %s",      #a, #cmp, #b, message    ),0) : (ZMMK_UNIT_TEST_FAIL_FMT("ASSERT_CMP_MSG(%s%s%s, ...): %s",      #a, #cmp, #b, message    ),0)) ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_ASSERT_CMP(a, cmp, b)                    ZMMK_UNIT_TEST_WARN_PUSH_FMT() (void)((ZMMK_UNIT_TEST_BEGIN_FMT("ASSERT_CMP(%s%s%s, ...): ...",         #a, #cmp, #b             ),((a) cmp (b))) ? (ZMMK_UNIT_TEST_PASS_FMT("ASSERT_CMP(%s%s%s): Passed",           #a, #cmp, #b             ),0) : (ZMMK_UNIT_TEST_FAIL_FMT("ASSERT_CMP(%s%s%s): Failed",           #a, #cmp, #b             ),0)) ZMMK_UNIT_TEST_WARN_POP()

#define MMK_UNIT_TEST_REQUIRE_FMT(condition, format, ...)      ZMMK_UNIT_TEST_WARN_PUSH_FMT() if((ZMMK_UNIT_TEST_BEGIN_FMT("REQUIRE_FMT(%s, ...): " format,         #condition,   __VA_ARGS__),(condition))   ? (ZMMK_UNIT_TEST_PASS_FMT("REQUIRE_FMT(%s, ...): " format,         #condition,   __VA_ARGS__),0) : (ZMMK_UNIT_TEST_FAIL_REQ_FMT("REQUIRE_FMT(%s, ...): " format,         #condition,   __VA_ARGS__),1)) return ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_REQUIRE_MSG(condition, message)          ZMMK_UNIT_TEST_WARN_PUSH_FMT() if((ZMMK_UNIT_TEST_BEGIN_FMT("REQUIRE_MSG(%s, ...): %s",              #condition,   message    ),(condition))   ? (ZMMK_UNIT_TEST_PASS_FMT("REQUIRE_MSG(%s, ...): %s",              #condition,   message    ),0) : (ZMMK_UNIT_TEST_FAIL_REQ_FMT("REQUIRE_MSG(%s, ...): %s",              #condition,   message    ),1)) return ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_REQUIRE(condition)                       ZMMK_UNIT_TEST_WARN_PUSH_FMT() if((ZMMK_UNIT_TEST_BEGIN_FMT("REQUIRE(%s): ...",                      #condition               ),(condition))   ? (ZMMK_UNIT_TEST_PASS_FMT("REQUIRE(%s): Passed",                   #condition               ),0) : (ZMMK_UNIT_TEST_FAIL_REQ_FMT("REQUIRE_(%s): Failed",                  #condition               ),1)) return ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_REQUIRE_CMP_FMT(a, cmp, b, format, ...)  ZMMK_UNIT_TEST_WARN_PUSH_FMT() if((ZMMK_UNIT_TEST_BEGIN_FMT("REQUIRE_CMP_FMT(%s%s%s, ...): " format, #a, #cmp, #b, __VA_ARGS__),((a) cmp (b))) ? (ZMMK_UNIT_TEST_PASS_FMT("REQUIRE_CMP_FMT(%s%s%s, ...): " format, #a, #cmp, #b, __VA_ARGS__),0) : (ZMMK_UNIT_TEST_FAIL_REQ_FMT("REQUIRE_CMP_FMT(%s%s%s, ...): " format, #a, #cmp, #b, __VA_ARGS__),1)) return ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_REQUIRE_CMP_MSG(a, cmp, b, message)      ZMMK_UNIT_TEST_WARN_PUSH_FMT() if((ZMMK_UNIT_TEST_BEGIN_FMT("REQUIRE_CMP_MSG(%s%s%s, ...): %s",      #a, #cmp, #b, message    ),((a) cmp (b))) ? (ZMMK_UNIT_TEST_PASS_FMT("REQUIRE_CMP_MSG(%s%s%s, ...): %s",      #a, #cmp, #b, message    ),0) : (ZMMK_UNIT_TEST_FAIL_REQ_FMT("REQUIRE_CMP_MSG(%s%s%s, ...): %s",      #a, #cmp, #b, message    ),1)) return ZMMK_UNIT_TEST_WARN_POP()
#define MMK_UNIT_TEST_REQUIRE_CMP(a, cmp, b)                   ZMMK_UNIT_TEST_WARN_PUSH_FMT() if((ZMMK_UNIT_TEST_BEGIN_FMT("REQUIRE_CMP(%s%s%s): ...",              #a, #cmp, #b             ),((a) cmp (b))) ? (ZMMK_UNIT_TEST_PASS_FMT("REQUIRE_CMP(%s%s%s): Passed",           #a, #cmp, #b             ),0) : (ZMMK_UNIT_TEST_FAIL_REQ_FMT("REQUIRE_CMP(%s%s%s): Failed",           #a, #cmp, #b             ),1)) return ZMMK_UNIT_TEST_WARN_POP()

#ifndef MMK_UNIT_TEST_NO_SHORTHAND
	// Drop MMK_UNIT_ prefix
	#define ASSERT_FMT          MMK_UNIT_TEST_ASSERT_FMT
	#define ASSERT_MSG          MMK_UNIT_TEST_ASSERT_MSG
	#define ASSERT              MMK_UNIT_TEST_ASSERT
	#define ASSERT_CMP_FMT      MMK_UNIT_TEST_ASSERT_CMP_FMT
	#define ASSERT_CMP_MSG      MMK_UNIT_TEST_ASSERT_CMP_MSG
	#define ASSERT_CMP          MMK_UNIT_TEST_ASSERT_CMP

	#define REQUIRE_FMT         MMK_UNIT_TEST_REQUIRE_FMT
	#define REQUIRE_MSG         MMK_UNIT_TEST_REQUIRE_MSG
	#define REQUIRE             MMK_UNIT_TEST_REQUIRE
	#define REQUIRE_CMP_FMT     MMK_UNIT_TEST_REQUIRE_CMP_FMT
	#define REQUIRE_CMP_MSG     MMK_UNIT_TEST_REQUIRE_CMP_MSG
	#define REQUIRE_CMP         MMK_UNIT_TEST_REQUIRE_CMP
#endif // def MMK_UNIT_TEST_NO_SHORTHAND



#ifdef _MSC_VER
	#define ZMMK_UNIT_TEST_BREAK() ::DebugBreak()
	#define ZMMK_UNIT_TEST_BREAK_IF_DEBUGGER() (void)(::IsDebuggerPresent() ? (ZMMK_UNIT_TEST_BREAK(),0) : 0)
	#define ZMMK_UNIT_TEST_WARN_PUSH_FMT() __pragma(warning(push)) __pragma(warning(error: 4473 4474 4475 4476 4477 4478))
	#define ZMMK_UNIT_TEST_WARN_POP()      __pragma(warning(pop))
#elif defined __clang__ // GCC isn't flexible enough to handle _Pragma s mid-statement.
	#define ZMMK_UNIT_TEST_BREAK() ((void)0)
	#define ZMMK_UNIT_TEST_BREAK_IF_DEBUGGER() ((void)(false ? (ZMMK_UNIT_TEST_BREAK(),0) : 0))
	#define ZMMK_UNIT_TEST_WARN_PUSH_FMT() _Pragma("GCC diagnostic push") _Pragma("GCC diagnostic error \"-Wformat\"")
	#define ZMMK_UNIT_TEST_WARN_POP()      _Pragma("GCC diagnostic pop")
#else
	#define ZMMK_UNIT_TEST_BREAK() ((void)0)
	#define ZMMK_UNIT_TEST_BREAK_IF_DEBUGGER() ((void)(false ? (ZMMK_UNIT_TEST_BREAK(),0) : 0))
	#define ZMMK_UNIT_TEST_WARN_PUSH_FMT()
	#define ZMMK_UNIT_TEST_WARN_POP()
#endif

#ifdef __GNUC__
	// reportCheck itself is already annotated, we don't need to bother with additional annotations here.
	#define ZMMK_UNIT_TEST_CHECK_FMT(format, ...)     ((void)0)
#else
	// VS2015 u1 can generate printf format warnings for the standard library, even without /ANALYZE.
	// Sadly it cannot do the same for our own non-stdlib code, despite using the same annotations.  Presumably they only work for non-stdlib code in /ANALYZE builds.
	// However, we can generate a (non-evaluated) call to snprintf to get the same benifits for our own macros.  Neat!
	#define ZMMK_UNIT_TEST_CHECK_FMT(format, ...)     ((void)(false ? snprintf(::mmk::test::unit::internal::forcePrintfCheck, sizeof(::mmk::test::unit::internal::forcePrintfCheck), format, __VA_ARGS__) : 0))
#endif

#define ZMMK_UNIT_TEST_BEGIN_FMT(format, ...)     ((void)((ZMMK_UNIT_TEST_CHECK_FMT(format, __VA_ARGS__), ::mmk::test::unit::internal::skipFormatBegin) ? (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultBegin,0),0) : (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultBegin, format, __VA_ARGS__),0)))
#define ZMMK_UNIT_TEST_PASS_FMT(format, ...)      ((void)((ZMMK_UNIT_TEST_CHECK_FMT(format, __VA_ARGS__), ::mmk::test::unit::internal::skipFormatPass ) ? (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultPass, 0),0) : (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultPass,  format, __VA_ARGS__),0)))
#define ZMMK_UNIT_TEST_FAIL_FMT(format, ...)      ((void)((ZMMK_UNIT_TEST_CHECK_FMT(format, __VA_ARGS__), ::mmk::test::unit::internal::skipFormatFail ) ? (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultFail, 0),0) : (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultFail,  format, __VA_ARGS__),ZMMK_UNIT_TEST_BREAK_IF_DEBUGGER(),0)))
#define ZMMK_UNIT_TEST_FAIL_REQ_FMT(format, ...)  ((void)((ZMMK_UNIT_TEST_CHECK_FMT(format, __VA_ARGS__), ::mmk::test::unit::internal::skipFormatFail ) ? (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultFail, 0),0) : (::mmk::test::unit::internal::reportCheck(::mmk::test::unit::checkResultFail,  format, __VA_ARGS__),ZMMK_UNIT_TEST_BREAK_IF_DEBUGGER(),0)))

namespace mmk { namespace test { namespace unit { namespace internal {
#ifndef __GNUC__
	namespace { char forcePrintfCheck[] = ""; }
#endif

	extern bool skipFormatBegin;
	extern bool skipFormatPass;
	extern bool skipFormatFail;

#ifdef _MSC_VER
	void reportCheck(unit::checkResult r, _Printf_format_string_ const char* format, ...);
#elif defined(__GNUC__)
	void reportCheck(unit::checkResult r, const char* format, ...) __attribute__ ((format(printf, 2, 3)));
#else
	void reportCheck(unit::checkResult r, const char* format, ...);
#endif
}}}} // namespace mmk::test::unit::internal

#endif /* ndef ZMMK_TEST_UNIT_CHECKS_HPP */
