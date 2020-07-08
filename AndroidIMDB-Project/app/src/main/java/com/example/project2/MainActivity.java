package com.example.project2;

//Joshua Rowan
//2-29-2020
//CS 478

import android.app.ListActivity;
import android.content.Intent;
import android.location.Address;
import android.net.Uri;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.view.menu.ListMenuItemView;

import java.util.ArrayList;
import java.util.List;

import static android.view.Menu.NONE;


public class MainActivity extends ListActivity {
    public int X=0;
    protected static final String EXTRA_RES_ID = "POS";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.mainactivity);

        String[] Titlelist = {"Parasite","Blade Runner 2049","Bohemian Rhapsody","Joker","Jumanji: The next level","The Irishman","Avengers: Endgame","Alita: Battle Angel","The Martian","Aquaman"};
        String[] Yearlist = {"2019","2017","2018","2019","2019","2019","2019","2019","2015","2018"};
        int[] Imglist = {R.drawable.tn1,R.drawable.tn2,R.drawable.tn3,R.drawable.tn4,R.drawable.tn5,R.drawable.tn6,R.drawable.tn7,R.drawable.tn8,R.drawable.tn9,R.drawable.tn10};

        MovieAdapter mAdapt = new MovieAdapter(this, Titlelist,Yearlist,Imglist);

          // old code to switch from ListActivity to AppCompatActivity.
        //ListView lv= (ListView) findViewById(R.id.listview);
        //lv.setAdapter(mAdapt);

        final ListView lv= getListView();
        setListAdapter(mAdapt);
        lv.setLongClickable(true);
        lv.setTextFilterEnabled(true);

        //registerForContextMenu(lv);

        lv.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View v,
                                           int position, long id) {
                X=position;
                registerForContextMenu(getListView());
                getListView().showContextMenu();
                Toast.makeText(getApplicationContext(), "Long Clicked : " , Toast.LENGTH_LONG).show();
                return true;
            }
        });


    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);

        menu.setHeaderTitle("Context Menu");
        menu.add(0, X, 0, "More Info");
        menu.add(0, X, 0, "Trailer");
        menu.add(0, X, 0, "Director");
        menu.add(0, X, 0, "IMDB-Webpage");
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        //major failure getting position through menuitem, only way to resolve was through external variable.
        Toast.makeText(this, "Selected Item: " +item.getTitle(), Toast.LENGTH_SHORT).show();
        String[] imdbsites =getResources().getStringArray(R.array.IMDBsites);
        String[] trailersites = getResources().getStringArray(R.array.Trailersites);
        String[] directorsites = getResources().getStringArray(R.array.DirectorSites);

        if (item.getTitle() == "More Info"){
            Intent intent = new Intent(this, InfoActivity.class);

            intent.putExtra(EXTRA_RES_ID, item.getItemId());
            startActivity(intent);
        }

        if (item.getTitle() == "Trailer"){
            Uri uri = Uri.parse(trailersites[item.getItemId()]);
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
            startActivity(intent);
        }

        if (item.getTitle() == "Director"){
            Uri uri = Uri.parse(directorsites[item.getItemId()]);
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
            startActivity(intent);
        }

        if (item.getTitle()=="IMDB-Webpage"){
            Uri uri = Uri.parse(imdbsites[item.getItemId()]);
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
            startActivity(intent);
        }

        return true;
    }

    @Override
    public void onListItemClick(ListView parent, View view,
                                int position, long id) {
        Intent intent = new Intent(MainActivity.this, ImgViewActivity.class);
        intent.putExtra(EXTRA_RES_ID, (int) id);
        startActivity(intent);

    }


}
