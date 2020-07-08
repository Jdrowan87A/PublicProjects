package com.example.project3a2;

import android.app.Fragment;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;


public class RestDescFrag extends Fragment {

    private TextView mRestDescView = null;
    private int mCurrIdx = -1;
    private int mRestDescArrayLen =0;

    private static final String TAG = "RestDescFrag";

    public int getShownIndex(){return mCurrIdx;}

    public void showItemAtIndex(int newIndex){
        if(newIndex<0 || newIndex >= mRestDescArrayLen){
            return;
        }
        mCurrIdx = newIndex;
       // mRestDescView.setText(RestActivity.restDesc[mCurrIdx]);
        String X = RestActivity.restDesc[mCurrIdx];
        //Toast.makeText(getContext(),X, Toast.LENGTH_LONG).show();
        Intent i = new Intent(Intent.ACTION_VIEW);
        i.setData(Uri.parse(X));
        getActivity().startActivity(i);

    }

    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setRetainInstance(true);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
        return inflater.inflate(R.layout.rest_desc_layout,container,false);
    }

    @Override
    public void onActivityCreated(Bundle savedInstanceState){
        super.onActivityCreated(savedInstanceState);

        mRestDescView = getActivity().findViewById(R.id.rest_desc);
        mRestDescArrayLen = RestActivity.restDesc.length;
        showItemAtIndex(mCurrIdx);
    }

    @Override
    public void onDestroy() {
        Log.i(TAG, getClass().getSimpleName() + ":onDestroy()");
        super.onDestroy();
    }

    @Override
    public void onDestroyView() {
        Log.i(TAG, getClass().getSimpleName() + ":onDestroyView()");
        super.onDestroyView();
    }

    @Override
    public void onDetach() {
        Log.i(TAG, getClass().getSimpleName() + ":onDetach()");
        super.onDetach();
    }

    @Override
    public void onPause() {
        Log.i(TAG, getClass().getSimpleName() + ":onPause()");
        super.onPause();
    }

    @Override
    public void onResume() {
        Log.i(TAG, getClass().getSimpleName() + ":onResume()");
        super.onResume();
    }

    @Override
    public void onStart() {
        Log.i(TAG, getClass().getSimpleName() + ":onStart()");
        super.onStart();
    }

    @Override
    public void onStop() {
        Log.i(TAG, getClass().getSimpleName() + ":onStop()");
        super.onStop();
    }
}
