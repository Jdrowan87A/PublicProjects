#include <iostream>
#include <string>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
int TESTMODE = 1;

void TESTER(unsigned int X){
	if (TESTMODE == 1){
		cout<<"TEST-INT:: "<<X<<" ::\n";
	}
};

void TESTER(unsigned char X){
	if (TESTMODE == 1){
		cout<<"TEST-CHAR:: "<<X<<" ::\n";
	}
};

void TESTER(string X){
	if (TESTMODE == 1){
		cout<<"TEST-STRING:: "<<X<<" ::\n";
	}
};

void TESTER(unsigned int X,string Y){
	if (TESTMODE == 1){
		cout<<Y<<" ";
		cout<<"TEST-INT:: "<<X<<" ::\n";
	}
};

void TESTER(unsigned char X,string Y){
	if (TESTMODE == 1){
		cout<<Y<<" ";
		cout<<"TEST-CHAR:: "<<X<<" ::\n";
	}
};

void TESTER(string X,string Y){
	if (TESTMODE == 1){
		cout<<Y<<" ";
		cout<<"TEST-STRING:: "<<X<<" ::\n";
	}
};
