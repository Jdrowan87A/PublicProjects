#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int isSpecial(char x){
	if (x>= 65 && x<= 90){
		return 0;
	}
	
	if(x>=48 && x<=57){
		return 0;
	}
	
	return 1;
}

int BroadCheck(string x){
	if(isSpecial(x[0])){
		return 0;
	}
	
	if(!(!(x.find("\"") != string::npos)
		&& !(x.find("#") != string::npos)
		&& !(x.find("$") != string::npos)
		&& !(x.find("'") != string::npos)
		&& !(x.find(",") != string::npos)
		&& !(x.find("*") != string::npos)
		&& !(x.find("+") != string::npos)
		&& !(x.find("(TV)") != string::npos)
		&& !(x.find("(V)") != string::npos)
		&& !(x.find("(VG)") != string::npos)
		&& !(x.find("????") != string::npos)
		&& !(x.find("/I") != string::npos)
		&& !(x.find("I)") != string::npos))){
		return 0;		
	}
	
	return 1;
	
}

void editCertificates(string readmyFile, string writemyFile){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	
	
	fileREAD.open(readmyFile.c_str());
	fileWrite.open(writemyFile.c_str());
	while(!fileREAD.eof()){
		getline(fileREAD,line);
		
		if((line.find("USA:G") != string::npos 
			|| (line.find("USA:PG") != string::npos)
			|| (line.find("USA:PG-13") != string::npos)
			|| (line.find("USA:R") != string::npos)
			|| (line.find("USA:Passed") != string::npos)
			|| (line.find("USA:Approved") != string::npos))
			&& !(line.find("{") != string::npos)
			&& !(line.find("(V)") != string::npos)
			&& !(line.find("/I)") != string::npos)
			&& !(line.find(",") != string::npos)
			&& line[0] != '.' && line[0] != '(' 
			&& line[0] != '&'  && line[0] != '%'
			&& line[0] != '"' && line[0] != '-'
			&& line[0] != '/'&& line[0] != '$' 
			&& line[0] != '\''
			&& line[0] != '*'
			){
				
				string newline="";
				line.erase(remove(line.begin(), line.end(), '"'), line.end());
				int sRemove = 0;
				int Term =0;
				int Term2=0;
				
				
				
				for(int i=0;i<(line.length());i++){
					if( line[i-1]==')' && Term ==0 ){
						newline+=',';
						
						sRemove=1;
					}else if(sRemove==0){
						newline+=line[i];
					}else if(sRemove==1 && !isspace(line[i]) ){
						
						if(line[i] == '(' && Term==1){
							Term2=1;
						}
						
						if(line[i] == 'U'){
							Term=1;
						}
						
						if(Term2==0 || Term==0){
							newline+=line[i];
						}
					}
				}
				
				fileWrite<< newline;
				fileWrite<<"\n";
		
		}
	}
	
}

void editGenres(string readmyFile, string writemyFile){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	
	fileREAD.open(readmyFile.c_str());
	fileWrite.open(writemyFile.c_str());
	while(!fileREAD.eof()){
		getline(fileREAD,line);
		int fail=0;
		if(!(line.find("{") != string::npos)
			&& !(line.find("\"") != string::npos)
			&& !(line.find("#") != string::npos)
			&& !(line.find("$") != string::npos)
			&& !(line.find("'") != string::npos)
			&& !(line.find(",") != string::npos)
			&& !(line.find("*") != string::npos)
			&& !(line.find("+") != string::npos)
			&& !(line.find("(TV)") != string::npos)
			&& !(line.find("(VG)") != string::npos)
			&& !(line.find("(V)") != string::npos)
			&& !(line.find("(????)") != string::npos)
			&& !(line.find("/I") != string::npos)
			&& !(line.find("I)") != string::npos)
			&& line[0] != '.' && line[0] != '(' 
			&& line[0] != '&'  && line[0] != '%'
			&& line[0] != '"' && line[0] != '-'
			&& line[0] != '/'
			){
			
			string newline="";
			int sRemove=0;
			for (int i=0;i<line.length();i++){
				
				if(sRemove==0){	
					newline+=line[i];
				}else if(!isspace(line[i])){
					newline+=line[i];
				}
				if (line[i]==')' && line[i-5]=='(' && isdigit(line[i-4])&& isdigit(line[i-3])&& isdigit(line[i-2])&& isdigit(line[i-1])){
					newline+=',';
					sRemove=1;
				}
				
				
			}
				
				fileWrite<< newline;
				fileWrite<<"\n";
			
		}
		
	}
}


int CheckFileFor(string X){
	
}

void editKeywords(string readmyFile, string writemyFile){
	ifstream fileREAD;
	ofstream fileWrite;	
	ofstream fileKey;
	ofstream tempFile;
	ofstream tempFile2;
	string line;
	
	////////generates new key list.
	////////generates new list of movies
	fileREAD.open(readmyFile.c_str());
	fileWrite.open(writemyFile.c_str());
	fileKey.open("Key.txt");
	tempFile.open("temp.txt");
	tempFile2.open("temp2.txt");
	int N=0;
	int Breaker =0;
	while(!fileREAD.eof()){
		getline(fileREAD,line);
		
		if(line == "start program"){
			Breaker=1;
		}
		
		if(Breaker==0){
			string msg="";
			
			for(int i=0;i<line.length();i++){
				if (line[i+1]== '('){
					msg+=",";
				}else{
					msg+=line[i];
				}
				if (line[i] =='(' && isspace(line[i+1])){
					msg+='\n';
				}
				
				if(line[i] == '\t'){
					msg+='\n';
				}
				/*
				if(line[i]==')'){
					msg+='\n';
				}
				*/
				
			}
			if((msg.find("(") != string::npos)
				&&(msg.find(")") != string::npos)){
					fileKey<<msg;
				}	
		}
		
		if (Breaker == 1){
			if (BroadCheck(line)){
				string m = "";
				int trip = 0;
				
				for (int i = 0; i<line.length(); i++){
					if(trip == 0){
					m+=line[i];
					}
					
					if(line[i] == ')' && line[i-5]=='('){
						m+=',';
						trip=1;
					}
					
					if(trip==1){
						if(!isspace(line[i]) && line[i] != '\t' && line[i]!=')'){
							m+=line[i];
						}
					}
				}
				if(N==0){
					tempFile<<m;
					tempFile<<"\n";
					if(m[0] == 'M'){ N=1;
					}
				}else{
					tempFile2<<m;
					tempFile2<<"\n";
				}
			}
			
		}
		
	}
	
	fileKey.close();
	fileREAD.close();
	tempFile.close();
	
	////// Eliminates excess keywords by number of occurences.
	ifstream readKey;
	ofstream writeKey;
	readKey.open("Key.txt");
	writeKey.open("newKey.txt");
	while(!readKey.eof()){
		int fail = 0;
		getline(readKey,line);
		if(line == ""){continue;
		}
		
		
		string msg = "";
		int x =1;
		for(int i = 0; i<line.length();i++){
			if(line[i] == '(' && fail ==0){
				if(i+1 < line.length()){
					if(isspace(line[i+1])){
						fail=1;	
					}else{
						
						while(i<line.length() && line[i+x]!=')'){
							msg+=line[i+x];
							x++;
						}
					}
				}				
			}
		}
		int y;
		y= atoi(msg.c_str());
		
		if( y>=20 && fail == 0){
			writeKey<<line;
			writeKey<<"\n";
		}
	}
	readKey.close();
	writeKey.close();
	
	/////combines newk keylist with movies
	
	
	
	
}

void editMovies(string readmyFile, string writemyFile){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	
	fileREAD.open(readmyFile.c_str());
	fileWrite.open(writemyFile.c_str());
	while(!fileREAD.eof()){
		getline(fileREAD,line);
		if(!(line.find("(V)") != string::npos )
			&&(!(line.find("(TV)") != string::npos))
			&&(!(line.find("{") != string::npos))
			&&(!(line.find("????") != string::npos))
			&&!(isSpecial(line[0]))
			&&(line.find("(") != string::npos)
			&&(line.find(")") != string::npos)
			&&!(line.find(",") != string::npos)
			){
				string msg="";
				int BR=0;
				for(int i=0;i<line.length() ;i++){
					if(BR==0){
						msg+=line[i];
						
						if(line[i]==')'){
							BR=1;
						}
					}
					
					
					
				}
				
				fileWrite<<msg;
				fileWrite<<"\n";
			
		}
	}
}

void editRatings(string readmyFile, string writemyFile){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	
	fileREAD.open(readmyFile.c_str());
	fileWrite.open(writemyFile.c_str());
}

int DateChecker(string x){
	int fail=0;
	int s1=0;
	int s2=0;
	int counter=0;
	for (int i=0;i<x.length();i++){
		
		if(s1==1){
			if(x[i]=='-' && isdigit(x[i+1]) && isdigit(x[i+2]) && isdigit(x[i+3]) && isdigit(x[i+4])){
				return 1;
			}
		}
		
		if(x[i-6] == 'U' && x[i-5]== 'S' && x[i-4]=='A' && x[i-3] ==':' && isdigit(x[i-2]) && isdigit(x[i-1]) && x[i] == '-'){
			s1=1;
		}
		
		
	}
	
	return 0;
}

void editRelease(string readmyFile, string writemyFile){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	
	fileREAD.open(readmyFile.c_str());
	fileWrite.open(writemyFile.c_str());
	
	while(!fileREAD.eof()){
		getline(fileREAD,line);
		if(BroadCheck(line) && line.find("USA:") != string::npos){
			string msg="";
				int BR=0;
				int BRR=0;
				int count=2;
				int fail = 0;
				for(int i=0;i<line.length() ;i++){
					
					if(BR==0){
						msg+=line[i];
						if(line[i]==')' && line[i-5] == '(' && BRR==0){
							msg+=',';
							BR=1;
						}
						
						if(line[i]==')' && line[i-5] != '('){
							fail=1;
						}
						
					}
					
					if(BRR==1){
						if(isspace(line[i])&& count!=0){
							msg+='-';
							count--;
						}else if(line[i]=='('){
							msg+=',';
							msg+=line[i];
						}else if(!isspace(line[i])){
							msg+=line[i];
						}
					}
					if(line[i+1]=='U' && BRR==0){
						BRR=1;
					}
					
				}
			if(fail==0 && DateChecker(msg))	{
			
			fileWrite<<msg;
			fileWrite<<"\n";
			}
		}
	}
}

void editRun(){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	string hold="";
	
	fileREAD.open("G.txt");
	fileWrite.open("G2.txt");
	
	while(!fileREAD.eof()){
		string newl="";
		
		getline(fileREAD,line);
		int i=0;
		while(line[i-1]!=','){
			newl+=line[i];
			i++;
		}
		
		string newGenre="";
		while(i<line.length()){
			newGenre+=line[i];
			i++;
		}
		
		if(hold == newl){
			fileWrite<<" "<<newGenre;
		}else{
			fileWrite<<"\n"<<newl<<newGenre;
			hold=newl;
		}		
		
	}
	fileWrite.close();
	
	ifstream FR;
	ofstream FW;
	FR.open("G2.txt");
	FW.open("G3.txt");
	
	
	while(!FR.eof()){
		getline(FR,line);
		
		int i=0;
		string test="";
		int trip=0;
		while(i<line.length()){
			if(trip==1){
				test+=line[i];
				i++;
			}else{
				i++;
			}
			if(line[i]==','){
				trip=1;
			}
		}
		if(!(test.find("Short") != string::npos )
			&&!(test.find("News") != string::npos )
			&&!(test.find("Show") != string::npos )
			&&!(test.find("Sex") != string::npos )
			&&!(test.find("Erotica") != string::npos )
			&&!(test.find("Hardcore") != string::npos )){
			FW<<line;
			FW<<"\n";
		}
		
	}
	
	
	
	
}

void EditKey(){
	ifstream fileREAD;
	ofstream fileWrite;	
	string line;
	string hold="";
	
	fileREAD.open("tkey.txt");
	fileWrite.open("newkey.txt");
	
	while(!fileREAD.eof()){
		string newl="";
		
		getline(fileREAD,line);
		int i=0;
		while(line[i-1]!=','){
			newl+=line[i];
			i++;
		}
		
		string newGenre="";
		while(i<line.length()){
			newGenre+=line[i];
			i++;
		}
		
		if(hold == newl){
			fileWrite<<" "<<newGenre;
		}else{
			fileWrite<<"\n"<<newl<<newGenre;
			hold=newl;
		}		
		
	}
}
