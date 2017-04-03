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

#ifndef IG_EXAMPLE_TESTS_WRITE_ACTIVITY_HPP
#define IG_EXAMPLE_TESTS_WRITE_ACTIVITY_HPP
#ifdef __ANDROID__

#include <jni.h>
#include <stdio.h>

struct writeActivity : mmk::test::unit::listener {
	JNIEnv*   env;
	jobject   activity;
	jmethodID jmAddText;

	writeActivity(JNIEnv* env, jobject activity)
		: env(env)
		, activity(activity)
		, jmAddText(env->GetMethodID(env->GetObjectClass(activity), "addText", "(Ljava/lang/String;)V"))
	{
	}

	void addText(const char* line) {
		jstring jLine = env->NewStringUTF(line);
		env->CallVoidMethod(activity, jmAddText, jLine);
		env->DeleteLocalRef(jLine);
	}

	void onBeginCategory(const categoryEvent& event) { addText(event.category ? event.category : "(no category)"); addText("\n"); }
	void onEndCategory  (const categoryEvent&      ) { addText("\n"); }
	void onBeginTest    (const testEvent&     event) { addText("    - "); addText(event.test->title ? event.test->title : event.test->id ? event.test->id : "<unknown test>"); addText("\n"); }

	void onEndCheck     (const checkEvent&    event) {
		addText("        [");
		addText(event.result == mmk::test::unit::checkResultPass ? "pass" : "FAIL");
		addText("] ");
		addText(event.message ? event.message : "");
		addText("\n");
	}
};

#endif /* def __ANDROID__ */
#endif /* ndef IG_EXAMPLE_TESTS_WRITE_ACTIVITY_HPP */
