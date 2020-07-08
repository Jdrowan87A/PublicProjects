package com.example.project3a2;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.Toast;
//import android.support.v4.app.FragmentActivity;

//I give up. Finally got this ^ library imported and half the functions don't work.


import com.example.project3a2.RestTitleFrag.ListSelectionListener;


import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
//import androidx.fragment.app.FragmentActivity;
//import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

public class RestActivity extends AppCompatActivity implements ListSelectionListener {


    public static String[] restNames;
    public static String[] restDesc;

    private static final String TAG = "RestActivity";

    private RestTitleFrag mTitleFrag;
    private RestDescFrag mDescFrag;


    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        restNames = getResources().getStringArray(R.array.RestNames);
        restDesc = getResources().getStringArray(R.array.RestDesc);

        setContentView(R.layout.rest_layout);

       mTitleFrag = (RestTitleFrag) getFragmentManager().findFragmentById(R.id.resttitles);
       mDescFrag = (RestDescFrag) getFragmentManager().findFragmentById(R.id.restdesc);


        getSupportActionBar().setTitle("Restaurants in Chicago");



    }

    @Override
    public void onListSelection(int index) {
        if(mDescFrag.getShownIndex() != index){
            mDescFrag.showItemAtIndex(index);
        }
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

    @Override
    public void onConfigurationChanged(Configuration newConfig){
        super.onConfigurationChanged(newConfig);

        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE){
            Toast.makeText(this,"Config change",Toast.LENGTH_SHORT).show();


        }
    }
}
