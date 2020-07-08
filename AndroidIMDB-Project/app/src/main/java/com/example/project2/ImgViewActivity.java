package com.example.project2;

import java.util.ArrayList;
import java.util.Arrays;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListView;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.Toast;


public class ImgViewActivity extends Activity {
    public int X;
    @Override
    public void onCreate(Bundle savedInstanceState){

        super.onCreate(savedInstanceState);
        int[] imglist = {R.drawable.m1,R.drawable.m2,R.drawable.m3,R.drawable.m4,R.drawable.m5,R.drawable.m6,R.drawable.m7,R.drawable.m8,R.drawable.m9,R.drawable.m10};
        String[] imdbsites = getResources().getStringArray(R.array.IMDBsites);
        Intent intent = getIntent();

        ImageView imageview = new ImageView(getApplicationContext());
        int id = intent.getIntExtra(MainActivity.EXTRA_RES_ID,0);
        X=id;
        imageview.setImageResource(imglist[id]);
        //imageview.setImageResource(intent.getIntExtra(MainActivity.EXTRA_RES_ID, 0));

        setContentView(imageview);

        imageview.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                Toast.makeText(getApplicationContext(),"Image Clicked", Toast.LENGTH_LONG).show();
                String[] imdbsites = getResources().getStringArray(R.array.IMDBsites);
                Uri uri = Uri.parse(imdbsites[X]);
                Intent intent = new Intent(Intent.ACTION_VIEW, uri);
                startActivity(intent);
            }
        });
    }


}
