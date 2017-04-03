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

UNIT_TEST_CATEGORY("Assertions")
{
	UNIT_TEST("Basic")
	{
		ASSERT(true);
		ASSERT(false);
		ASSERT_MSG(true, "Message");
		ASSERT_MSG(false, "Message");
		ASSERT_FMT(true, "Format: %d", 42);
		ASSERT_FMT(false, "Format: %d", 42);
	}

	UNIT_TEST("Comparison")
	{
		ASSERT_CMP(1,<,2);
		ASSERT_CMP(1,>=,2);
		ASSERT_CMP_MSG(1,<,2, "Message");
		ASSERT_CMP_MSG(1,>=,2, "Message");
		ASSERT_CMP_FMT(1,<,2, "Format: %d", 42);
		ASSERT_CMP_FMT(1,>=,2, "Format: %d", 42);
	}
}

UNIT_TEST_CATEGORY("Requires")
{
	UNIT_TEST("Basic")
	{
		REQUIRE(true);
		REQUIRE(false);
		REQUIRE_MSG(true, "Message");
		REQUIRE_MSG(false, "Message");
		REQUIRE_FMT(true, "Format: %d", 42);
		REQUIRE_FMT(false, "Format: %d", 42);
	}

	UNIT_TEST("Comparison")
	{
		REQUIRE_CMP(1,<,2);
		REQUIRE_CMP(1,>=,2);
		REQUIRE_CMP_MSG(1,<,2, "Message");
		REQUIRE_CMP_MSG(1,>=,2, "Message");
		REQUIRE_CMP_FMT(1,<,2, "Format: %d", 42);
		REQUIRE_CMP_FMT(1,>=,2, "Format: %d", 42);
		//REQUIRE_CMP_FMT(1,>=,2, "Format: %s", 42); // Trigger bug
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
	return mmk::test::unit::run(argc, argv) == 0 ? 1 : 0; // Invert error condition - we have several failing tests above, intentionally.
}

#endif
