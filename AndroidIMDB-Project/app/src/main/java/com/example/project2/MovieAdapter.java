package com.example.project2;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;

import java.util.ArrayList;

public class MovieAdapter extends ArrayAdapter<String> {

    Context Xcontext;
    private String[] title;
    private String[] year;
    private int[] img;

    public MovieAdapter(Context context, String[] title, String[] year, int[] img){
        super(context, R.layout.list_desc);
        this.title = title;
        this.year = year;
        this.img = img;
        this.Xcontext=context;
    }

    @Override
    public int getCount() {
        return title.length;
    }

    @NonNull
    @Override
    public View getView(int postition, View convertView, ViewGroup parent){
        ViewHolder mViewHolder = new ViewHolder();
        if (convertView == null){
            LayoutInflater mInflate = (LayoutInflater) Xcontext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = mInflate.inflate(R.layout.list_desc,parent,false);
            mViewHolder.imgH = (ImageView) convertView.findViewById(R.id.imageView1);
            mViewHolder.titleH = (TextView) convertView.findViewById(R.id.textView2);
            mViewHolder.yearH = (TextView) convertView.findViewById(R.id.textView3);
            convertView.setTag(mViewHolder);
        }else{
            mViewHolder = (ViewHolder) convertView.getTag();
        }
        mViewHolder.imgH.setImageResource(img[postition]);
        mViewHolder.titleH.setText(title[postition]);
        mViewHolder.yearH.setText(year[postition]);

        return convertView;
    }

    static class ViewHolder{
        ImageView imgH;
        TextView titleH;
        TextView yearH;
    }
}
