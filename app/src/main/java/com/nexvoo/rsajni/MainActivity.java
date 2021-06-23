package com.nexvoo.rsajni;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        text = findViewById(R.id.text);
    }

    public void encrypt(View view) {
        String result = RsaJni.encrypt("12345678");
        text.setText(result);
    }

    public void decrypt(View view) {
        String result = RsaJni.decrypt(text.getText().toString());
        text.setText(result);
    }
}