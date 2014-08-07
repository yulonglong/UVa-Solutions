//uva 755
#include <bits/stdc++.h>
using namespace std;

char getChar(char letter){
	if((letter=='A')||(letter=='B')||(letter=='C')){
		return '2';
	}
	else if((letter=='D')||(letter=='E')||(letter=='F')){
		return '3';
	}
	else if((letter=='G')||(letter=='H')||(letter=='I')){
		return '4';
	}
	else if((letter=='J')||(letter=='K')||(letter=='L')){
		return '5';
	}
	else if((letter=='M')||(letter=='N')||(letter=='O')){
		return '6';
	}
	else if((letter=='P')||(letter=='R')||(letter=='S')){
		return '7';
	}
	else if((letter=='T')||(letter=='U')||(letter=='V')){
		return '8';
	}
	else if((letter=='W')||(letter=='X')||(letter=='Y')){
		return '9';
	}
	else if((letter>='0')&&(letter<='9')){
		return letter;
	}
	return 'Q';
}

string convert(string input){
	string result;
	unsigned int length = input.length();
	for(unsigned int i=0;i<length;i++){
		if(input[i]!='-'){
			char tempChar = getChar (input[i]);
			result = result+tempChar;
		}
	}
	string answer;
	length = result.length();
	for(unsigned int i=0;i<length;i++){
		if(i==3){
			answer=answer+'-';
		}
		answer= answer +result[i];
	}
	return answer;
}

map<string,int> m;
map<string,int>::iterator it;

int main(){
	//freopen("in.txt","r",stdin);
	int tc;
	cin >> tc;
	for(int d=1;d<=tc;d++){
		m.clear();
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			string input;
			cin >> input;
			string answer;
			answer = convert(input);
			//cout << answer << endl;
			it=m.find(answer);
			if(it==m.end()){
				m.insert(pair<string,int>(answer,1));
			}
			else{
				it->second=it->second+1;
			}
		}
		if(d>1){
			cout << endl;
		}
		
		bool found=false;
		for(it=m.begin();it!=m.end();it++){
			if(it->second>1){
				found=true;
				cout << it->first << " " << it->second << endl;
			}
		}
		if(!found){
			cout<< "No duplicates." << endl;
		}
				
	}
	
}
