package com.example.project2;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class InfoActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.info_act);

        Intent intent = getIntent();
        int id = intent.getIntExtra(MainActivity.EXTRA_RES_ID,0);

        String[] Rating1 = {"8.6/10","8/10","8/10","8.6/10","6.9/10","8/10","8.5/10","7.3","8/10","7/10"};
        String[] Rating2 = {"99%","87%","60%","68%","71%","96%","94%","61%","91%","66%"};
        String[] DName = getResources().getStringArray(R.array.DirectorName);
        String[] info = getResources().getStringArray(R.array.MovieInfo);

        TextView ReleaseDate = (TextView)findViewById(R.id.textView4);
        TextView DirectorName = (TextView)findViewById(R.id.textView5);
        TextView RatingAlpha = (TextView)findViewById(R.id.textView6);
        TextView RatingBeta = (TextView)findViewById(R.id.textView7);

        ReleaseDate.setText(info[id]);
        DirectorName.setText("Director: " +DName[id]);
        RatingAlpha.setText("IMDb Rating: " + Rating1[id]);
        RatingBeta.setText("Rotten Tomatoes Rating: " + Rating2[id]);

    }
}
