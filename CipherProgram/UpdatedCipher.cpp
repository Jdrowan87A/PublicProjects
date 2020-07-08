#include <iostream>
#include <string>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

int toInt(char c){
	int x;
	if(isupper(c)){
		return c-65;
	}else{
		return c-97;
	}
}

char toChar(int i){
	char C;
	if (i>=0){
		i = i%26;
		C = i+97;
	}else{
		while(i<0){
			i=i+26;
		}
		C= i +97;
	}
	return C;
}



void decryptShift(string input){
	int alpha[input.length()];
	string msg;
	char c;
	
	for (int i = 0;i<input.length();i++){
		alpha[i] = toInt(input[i]);
		
	}
	
	for (int i = 0; i<26; i++){
		msg="";
		
		for (int j = 0; j<input.length(); j++){
			c = ((alpha[j]+i)%26)+97;
			msg+=c;
		}
		cout<<endl;
		cout<<"shift is: "<<i<<endl;
		
			cout<<msg<<endl;
		
	}
}

//find most common letter
char FMC(string input,int printer){
	int alpha[26];
	for (int i = 0; i<26 ; i++){
		alpha[i] = 0;
	}
	
	for (int i = 0; i<input.length(); i++){
		int x = toInt(input[i]);
		alpha[x]++;
	}
	
	int MCL = 0;
	for (int i=0; i<26; i++){
		if (alpha[i]>alpha[MCL]){
			MCL = i;
		}
	}
	
	if(printer ==1){
		char c;
		for(int i = 0; i<26; i++){
			c = i + 97;
			cout<<c<<":"<<alpha[i]<<" ";
		}
		cout<<endl;
	}
	char L = MCL + 97;
	return L;
}

int coprime(int a, int b) { 
      
    if ( __gcd(a, b) == 1) 
        return 1;  
    else
        return 0;       
} 

int AffineChecker(int C, int a, int b){
	int x = (C/a)-b;
	if (x == 4){
		return 1;
	}
	
	if((C/(a+26))-b == 4){
		return 1;
	}
	
	if((C/(a+52))-b == 4){
		return 1;
	}
	
	return 0;
}

 affineDecrypt(string input,int E){
 	char M = FMC(input,0);
 	int C = M-97;
	string msg ="";
	int alpha[input.length()];
	//char c;
	
	
	for (int i=0; i<input.length(); i++){
		alpha[i]=toInt(input[i]);
	}
		
	for (int a=0;a<100;a++){
		for (int b=0;b<26;b++){
			msg="";
			if (coprime(a,26) == 1 /*&& AffineChecker(C,a,b)==1*/){
				for (int i = 0; i < input.length();i++){
					msg += toChar(((alpha[i]-b)/a)%26);
				}
			if(msg[0] == 's' && msg[1] == 'y'){
				cout<<"a="<<a<<" b="<<b<<endl<<msg<<endl;
			}
			}
		}
	}
}

int cipherMax(int ciph[],int size){
	int trip =0;
	for (int i=0; i<size;i++){
		if (ciph[i] == 25){
			trip++;
		} 
	}
	if (trip == size){
		return 1;
	}else{
		return 0;
	}	
}

void decryptVigenere(string input,int startSize, int endSize,char letter){
	int alpha[input.length()];
	string msg;
	string ciphmsg;
	int chosenLetter = toInt(letter);
	
	for (int i =0; i<input.length(); i++){
		alpha[i]=toInt(input[i]);
	}
	
	for (int k = startSize; k<=endSize; k++){
		msg="";
		int ciph[k]; // cipher array. Every integer held in the cipher will be added to the message in rotation
		for (int a=0;a<k;a++){ // initializes the cipher array to all 0's
				ciph[a]=0;
			}
		
		
			ciphmsg="";
			for (int i=0; i<k; i++){
				string tempMSG="";
				for (int j=0;j<input.length();j++){
					if (j%k == i){
						tempMSG+=input[j];
					}
					
				}
				//cout<<tempMSG<<endl;
				char beta = FMC(tempMSG,0);
				//cout<<i<<":"<<beta<<endl;
				
				if (beta-101 <0){
					ciph[i] = beta - 71 -chosenLetter;
				}else{
					ciph[i] = beta - 97 - chosenLetter;
				}
				
				ciphmsg += ciph[i] + 97;
				
				
			}
			for (int i = 0; i<input.length(); i++){
				if (alpha[i] - ciph[i%k] < 0){
					msg += (26 + (alpha[i] - ciph[i%k]))+97;
				}else{
				msg += toChar((alpha[i] - ciph[i%k])%26) ;
				}
			}
			cout<<ciphmsg<<endl<<msg<<endl;
			
	}
		
	
}


void EncryptAffine(string input, int a, int b){
	int alpha[input.length()];
	string msg = "";
	int x = a;
	int y = b;
	
	for (int i = 0; i<input.length(); i++){
		alpha[i]=toInt(input[i]);
	}
	
	for (int i = 0; i<input.length(); i++){
		msg += toChar(((alpha[i]*a)+b)%26);
	}
	if (msg[0] == 'u' && msg[1] == 'i'){
	
	cout<<endl<<msg<<endl<<cout<<" hi"<<x<<" "<<y<<endl;
	}
}

void EncryptVigenere(string input, string cipher){
	int alpha[input.length()];
	int ciphnum[cipher.length()];
	string msg="";
	
	for (int i = 0; i<input.length(); i++){
		alpha[i]=toInt(input[i]);
	}
	for (int i = 0; i<cipher.length();i++){
		ciphnum[i]=toInt(cipher[i]);
	}
	
	for (int i = 0; i<input.length(); i++){
		msg += toChar((alpha[i]+ciphnum[i%(cipher.length())])%26);
	}
	
	cout<<endl<<msg<<endl;
}


int main(){
	int choice=0;
	cout<<"choose cipher to break: 1.Shift 2.Affine 3.Vigenere 4.EncryptShift 5.EncryptAffine 6.EncryptVigenere:: ";
	cin>>choice;
	string Input;
	cout<<"\ninput plaintext:\n";
	cin>>Input;
	if (choice == 1){
		decryptShift(Input);
	}else if(choice == 2){
		affineDecrypt(Input,4);
	}else if(choice == 3){
		int starter=0;
		int ender=0;
		char letter='e';
		cout<<"\nInput start size of decryptor key: ";
		cin>>starter;
		cout<<"Input end size of decrytpor key: ";
		cin>>ender;
		cout<<"choice for most common letter(lower case):";
		cin>>letter;
		decryptVigenere(Input,starter,ender,letter);
	}else if(choice ==4){
		
	}else if(choice == 5){
		
		for (int a =1;a<50;a++){
			for (int b =1; b<26; b++){
				EncryptAffine(Input,a,b);
			}
		}
		
		
	}else if(choice == 6){
		string CIPH;
		cout<<"input cipher string: ";
		cin>>CIPH;
		EncryptVigenere(Input,CIPH);
	
	}else{
		cout<<"\ninvalid entry in choice. Ending program.";
	}
}
