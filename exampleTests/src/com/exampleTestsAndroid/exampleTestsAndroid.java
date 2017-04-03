
package com.exampleTestsAndroid;

import android.app.Activity;
import android.widget.ScrollView;
import android.widget.TextView;
import android.os.Bundle;
import android.os.Handler;

public class exampleTestsAndroid extends Activity {
	static {
		System.loadLibrary("exampleTests");
	}

	StringBuilder logs;
	TextView      tv;

	@Override public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		logs = new StringBuilder();

		tv = new TextView(this);
		tv.setText(logs.toString());

		final ScrollView sv = new ScrollView(this);
		sv.addView(tv);

		final Handler handler = new Handler();
		handler.post(new Runnable() { @Override public void run() { runAllTests(); } });

		setContentView(sv);
	}

	void addText(final String text) {
		runOnUiThread(new Runnable() {
			@Override public void run() {
				logs.append(text);
				tv.setText(logs.toString());
			}
		});
	}

	native void runAllTests();
}
