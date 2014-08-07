//uva 12626
#include <bits/stdc++.h>
using namespace std;

int freq[120];

int main(){
	//freopen("in.txt","r",stdin);
	int tc;
	string word;
	getline(cin,word);
	tc = atoi(word.c_str());
	while(tc--){
		memset(freq,0,sizeof(freq));
		getline(cin,word);
		for(int i=0;i<(int)word.length();i++){
			freq[(int)word[i]]++;
		}
		int min=20000;
		if(freq['M']<min){
			min=freq['M'];
		}
		if(freq['A']/3<min){
			min=freq['A']/3;
		}
		if(freq['R']/2<min){
			min=freq['R']/2;
		}
		if(freq['G']<min){
			min=freq['G'];
		}
		if(freq['I']<min){
			min=freq['I'];
		}
		if(freq['T']<min){
			min=freq['T'];
		}
		cout << min << endl;
	}
	return 0;
}
