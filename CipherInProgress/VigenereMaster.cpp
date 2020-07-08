#include <iostream>
#include <string>
#include <cstdlib>
#include<bits/stdc++.h>
#include <fcntl.h>
#include <algorithm>
#include "testSuite.h"
#include "CharAnalyzer.h"
#include <io.h>

using namespace std;

void decryptV(string input,unsigned int Lang);
void encryptV(string input,string key,unsigned int Lang);
const int MaxKeyLen = 10;


int main(){
	int CONTRUN =1;
	unsigned int Selected;
	unsigned char Lang;
	
	cout<<"Welcome to Vigenere Cipher Multiple Language Decryptor!\n";
	
while( CONTRUN == 1){ // start while run loop
	Lang=-1;
	cout<<"Please select the language the cipher text is expected to be\n";
	cout<<"1.English 2.Spansih 3.Italian 4.Russian(non-functioning)\n'q' to quit\n ::> ";
	cin>>Lang;
	
	Selected = Lang - 48;
	
	
	//CONTRUN=0;
	
	//
	switch(Selected){
		case 1: cout<<"English has been chosen.\n";
			CONTRUN=0;
			break;
		case 2: cout<<"Spanish has been chosen.\n";
			CONTRUN=0;
			break;
		case 3: cout<<"Italian has been chosen.\n";
			CONTRUN=0;
			break;
		//case 4: cout<<"Russian has been chosen.\n";
		//	CONTRUN=0;
		//	break;
		case 65: cout<<"Ending Program.\n"; Lang=0; return 0;
			break;
		default: cout<<"No valid value entered\n"; continue;		
	}
	
}//end while run loop
	
	int DorE;
	cout<<"\n 1 for decrypt, 2 for encrypt: ";
	cin>>DorE;
	cout<<Selected<<endl;
	
		cout<<"\nEnter the entire cipher text now\n::";
		
		if(DorE == 1){
		
	
    	string CipherText;
		cin>>CipherText;
		cout<<CipherText<<endl;
		decryptV(CipherText,Selected);
		}else{
		
    	string Plaintext;
    	string key;
    	cin>>Plaintext;
    	cout<<"\nEnter Key: \n";
    	cin>>key;
    	encryptV(Plaintext,key,Selected);
		}
    	
return 0;
}

void decryptV(string input, unsigned int Lang){
	int L = Lang;
	int inputLength = input.length();
	string msg;
	int intArray[inputLength]; //array to hold all the integer values of the letters
	
	int MCLetter = 4; //our most common letter
	

	
	
	//Encodes letters to numbers in an array.
	for (int i=0; i<inputLength; i++){
		
		intArray[i]=ChartoInt(input[i],L); 
	}
	
	
	//find the probable length
	int alphaLen = 26;
	
	
	
} 



void encryptV(string input, string key,unsigned int Lang){
	
}


