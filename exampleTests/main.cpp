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

#include <mmk/test/unit.hpp>
#include "writeActivity.hpp"

bool gBug = false;

UNIT_TEST_CATEGORY("Assertions")
{
	UNIT_TEST("Basic")
	{
		const bool bug = gBug;
		gBug = true; // Bug unless we reach the end of this function.

		ASSERT(true);
		ASSERT(false);
		ASSERT_MSG(true, "Message");
		ASSERT_MSG(false, "Message");
		ASSERT_FMT(true, "Format: %d", 42);
		ASSERT_FMT(false, "Format: %d", 42);

		gBug = bug;
	}

	UNIT_TEST("Comparison")
	{
		const bool bug = gBug;
		gBug = true; // Bug unless we reach the end of this function.

		ASSERT_CMP(1,<,2);
		ASSERT_CMP(1,>=,2);
		ASSERT_CMP_MSG(1,<,2, "Message");
		ASSERT_CMP_MSG(1,>=,2, "Message");
		ASSERT_CMP_FMT(1,<,2, "Format: %d", 42);
		ASSERT_CMP_FMT(1,>=,2, "Format: %d", 42);

		gBug = bug;
	}

	UNIT_TEST("Use in an expression")
	{
		bool bug = gBug;
		gBug = true; // Bug unless we reach the end of this function

		if (!ASSERT_CMP(1,<,2))                        bug = true;
		if ( ASSERT_CMP(1,>=,2))                       bug = true;
		if (!ASSERT_CMP_MSG(1,<,2, "Message"))         bug = true;
		if ( ASSERT_CMP_MSG(1,>=,2, "Message"))        bug = true;
		if (!ASSERT_CMP_FMT(1,<,2, "Format: %d", 42))  bug = true;
		if ( ASSERT_CMP_FMT(1,>=,2, "Format: %d", 42)) bug = true;

		if (!ASSERT_CMP(1,<,2))                        { bug = true; }
		if ( ASSERT_CMP(1,>=,2))                       { bug = true; }
		if (!ASSERT_CMP_MSG(1,<,2, "Message"))         { bug = true; }
		if ( ASSERT_CMP_MSG(1,>=,2, "Message"))        { bug = true; }
		if (!ASSERT_CMP_FMT(1,<,2, "Format: %d", 42))  { bug = true; }
		if ( ASSERT_CMP_FMT(1,>=,2, "Format: %d", 42)) { bug = true; }

		gBug = bug;
	}
}

UNIT_TEST_CATEGORY("Requires")
{
	UNIT_TEST("Basic")
	{
		const bool bug = gBug; gBug = true; // Bug unless we pass the first REQUIRE...
		REQUIRE(true);  gBug = bug;         // We passed the first REQUIRE...
		REQUIRE(false); gBug = true;        // Bug if we reach the end of this function.
	}

	UNIT_TEST("Basic (MSG)")
	{
		const bool bug = gBug; gBug = true;         // Bug unless we pass the first REQUIRE...
		REQUIRE_MSG(true, "Message");  gBug = bug;  // We passed the first REQUIRE...
		REQUIRE_MSG(false, "Message"); gBug = true; // Bug if we reach the end of this function.
	}

	UNIT_TEST("Basic (FMT)")
	{
		const bool bug = gBug; gBug = true;                // Bug unless we pass the first REQUIRE...
		REQUIRE_FMT(true, "Format: %d", 42);  gBug = bug;  // We passed the first REQUIRE...
		REQUIRE_FMT(false, "Format: %d", 42); gBug = true; // Bug if we reach the end of this function.
	}

	UNIT_TEST("Comparison")
	{
		const bool bug = gBug; gBug = true; // Bug unless we pass the first REQUIRE...
		REQUIRE_CMP(1,<,2);  gBug = bug;    // We passed the first REQUIRE...
		REQUIRE_CMP(1,>=,2); gBug = true;   // Bug if we reach the end of this function.
	}

	UNIT_TEST("Basic (MSG)")
	{
		const bool bug = gBug; gBug = true;              // Bug unless we pass the first REQUIRE...
		REQUIRE_CMP_MSG(1,<,2, "Message");  gBug = bug;  // We passed the first REQUIRE...
		REQUIRE_CMP_MSG(1,>=,2, "Message"); gBug = true; // Bug if we reach the end of this function.
	}

	UNIT_TEST("Basic (MSG)")
	{
		const bool bug = gBug; gBug = true;                     // Bug unless we pass the first REQUIRE...
		REQUIRE_CMP_FMT(1,<,2, "Format: %d", 42);  gBug = bug;  // We passed the first REQUIRE...
		REQUIRE_CMP_FMT(1,>=,2, "Format: %d", 42); gBug = true; // Bug if we reach the end of this function.
	}
}

UNIT_TEST_CATEGORY("Compile time only")
{
	UNIT_TEST("Compile time")
	{
		//REQUIRE_CMP_FMT(1,>=,2, "Format: %s", 42); // Trigger formatting compile error
	}
}

#ifdef __ANDROID__
extern "C" JNIEXPORT void JNICALL Java_com_exampleTestsAndroid_exampleTestsAndroid_runAllTests(JNIEnv* env, jobject thiz) {
	using namespace mmk::test::unit;

	settings s = {};
	writeActivity actWriter(env, thiz);       s.listeners.push_back(&actWriter);
	writeAdbLog   logWriter("exampleTests");  s.listeners.push_back(&logWriter);
	run(s);
}

#else
int main(int argc, char** argv) {
	if (mmk::test::unit::run(argc, argv) == 0) gBug = true; // Tests should've returned an error code
	return gBug ? 1 : 0;
}

#endif
