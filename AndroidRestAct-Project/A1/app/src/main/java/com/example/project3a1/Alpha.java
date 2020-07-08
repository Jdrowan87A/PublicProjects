package com.example.project3a1;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.app.Activity;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class Alpha extends Activity {



    private Button B1;
    private Button B2;
    private IntentFilter RestFilter;
    private IntentFilter ActFilter;

    private static final String REST_INTENT = "com.example.project3a1.rest";
    private static final String ACT_INTENT = "com.example.project3a1.act";
    private static final String OUR_PERMISSION = "edu.uic.cs478.sp2020.project3";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.alpha_layout);

        B1 = findViewById(R.id.button1);
        B2 = findViewById(R.id.button2);

        B1.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                checkPermAndBroad1();
            }
        });

        B2.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                checkPermAndBroad2();
            }
        });

    }


    private void checkPermAndBroad1(){
        if(PackageManager.PERMISSION_GRANTED == ContextCompat.checkSelfPermission(this, OUR_PERMISSION)) {
            Intent myIntent = new Intent(REST_INTENT);
            sendOrderedBroadcast(myIntent, OUR_PERMISSION);
        }
        else{
            ActivityCompat.requestPermissions(this, new String[]{OUR_PERMISSION},0);
        }
    }
    private void checkPermAndBroad2(){
        if(PackageManager.PERMISSION_GRANTED == ContextCompat.checkSelfPermission(this, OUR_PERMISSION)) {
            Intent myIntent = new Intent(ACT_INTENT);
            sendOrderedBroadcast(myIntent, OUR_PERMISSION);
        }
        else{
            ActivityCompat.requestPermissions(this, new String[]{OUR_PERMISSION},0);
        }
    }


}
