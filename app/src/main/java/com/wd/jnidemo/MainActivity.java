package com.wd.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.wd.jnidemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'jnidemo' library on application startup.
    static {
        System.loadLibrary("jnidemo");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        JniEnter.init();
    }

    /**
     * A native method that is implemented by the 'jnidemo' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void initJNI();
}