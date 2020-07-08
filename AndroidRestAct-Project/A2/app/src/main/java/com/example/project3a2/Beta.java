package com.example.project3a2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.Toast;
import android.widget.Toolbar;

public class Beta extends AppCompatActivity {

    private static final String REST_INTENT = "com.example.project3a1.rest";
    private static final String ACT_INTENT = "com.example.project3a1.act";

    BroadcastReceiver RestReceiver = new myReceiver();
    BroadcastReceiver ActReceiver = new myReceiver();
    IntentFilter RestFilter = new IntentFilter(REST_INTENT);
    IntentFilter ActFilter = new IntentFilter(ACT_INTENT);


    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.beta_layout);

        RestFilter.setPriority(100);
        ActFilter.setPriority(100);

        registerReceiver(RestReceiver,RestFilter);
        registerReceiver(ActReceiver,ActFilter);

        getSupportActionBar().setTitle("Chicago App");
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu){
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.top_menu, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.launch1:
                Toast.makeText(getApplicationContext(), "Going to Restaurants",
                        Toast.LENGTH_LONG).show();
                Intent intent = new Intent(this,RestActivity.class);
                this.startActivity(intent);
                return true;
            case R.id.launch2:
                Toast.makeText(getApplicationContext(), "Going to Attractions",
                        Toast.LENGTH_LONG).show();
                Intent intent2 = new Intent(this, ActActivity.class);
                this.startActivity(intent2);
                return true;
            default:
                return false;
        }
    }

    public void onDestroy(){
        super.onDestroy();
        unregisterReceiver(RestReceiver);
        unregisterReceiver(ActReceiver);

    }

    public void onResume() {
        super.onResume()  ;
        if (ContextCompat.checkSelfPermission(this, "edu.uic.cs478.sp2020.project3") !=
                PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{"edu.uic.cs478.sp2020.project3"}, 0);
        }
    }

    public void onRequestPermissionsResult(int code, String[] permissions, int[] grantResults) {

        if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

            // Permission granted, go ahead and display map
            Log.i("p3rec", "p3 permission granted") ;
        }
        else {
            Toast.makeText(this, "BUMMER: No Permission :-(", Toast.LENGTH_LONG).show() ;
        }


    }


}
