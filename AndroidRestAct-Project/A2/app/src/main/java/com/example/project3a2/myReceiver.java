package com.example.project3a2;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import androidx.appcompat.app.AppCompatActivity;
import android.app.Activity;
import android.content.IntentFilter;
import android.util.Log;
import android.widget.Toast;

public class myReceiver extends BroadcastReceiver {

    private static final String REST_INTENT = "com.example.project3a1.rest";
    private static final String ACT_INTENT = "com.example.project3a1.act";
    @Override
    public void onReceive(Context arg0, Intent arg1){
        String A = arg1.toString();

        if (A.contains(REST_INTENT)){
            Toast.makeText(arg0, "Restaurant Toast!", Toast.LENGTH_LONG).show();
            Intent intent = new Intent(arg0,RestActivity.class);
            arg0.startActivity(intent);
        }

        if (A.contains(ACT_INTENT)){
            Toast.makeText(arg0, "Activities Toast!", Toast.LENGTH_LONG).show();
            Intent intent2 = new Intent(arg0, ActActivity.class);
            arg0.startActivity(intent2);
        }

    }
}
