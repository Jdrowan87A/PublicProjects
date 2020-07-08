package com.example.project3a2;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.Toast;


import androidx.appcompat.app.AppCompatActivity;

import com.example.project3a2.ActTitleFrag.ListSelectionListener;

public class ActActivity extends AppCompatActivity implements ListSelectionListener {


    public static String[] actNames;
    public static String[] actDesc;

    private static final String TAG = "ActActivity";

    private ActTitleFrag mTitleFrag2;
    private ActDescFrag mDescFrag2;

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        actNames = getResources().getStringArray(R.array.ActNames);
        actDesc = getResources().getStringArray(R.array.ActDesc);

        setContentView(R.layout.act_layout);

        mTitleFrag2 = (ActTitleFrag) getFragmentManager().findFragmentById(R.id.acttitles);
        mDescFrag2 = (ActDescFrag) getFragmentManager().findFragmentById(R.id.actdesc);

       getSupportActionBar().setTitle("Attractions in Chicago");
    }

    @Override
    public void onListSelection(int index) {
        if(mDescFrag2.getShownIndex() != index){
            mDescFrag2.showItemAtIndex(index);
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
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);

        // Checks the orientation of the screen
        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
        Toast.makeText(this, "horizontal", Toast.LENGTH_SHORT).show();
        } else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){
        Toast.makeText(this, "vertical", Toast.LENGTH_SHORT).show();
        }
    }


}
