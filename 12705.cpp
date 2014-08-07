//uva 12705
#include <bits/stdc++.h>
using namespace std;

int freq[93];
int weight[37];

void initialize(){
	memset(weight,0,sizeof(weight));
	weight[1]=2;
	weight[2]=3;
	weight[3]=3;
	weight[4]=4;
	weight[5]=4;
	weight[6]=4;
	weight[7]=5;
	weight[8]=5;
	weight[9]=5;
	weight[10]=5;
	weight[11]=6;
	weight[12]=6;
	weight[13]=6;
	weight[14]=6;
	weight[15]=6;
	weight[16]=7;
	weight[17]=7;
	weight[18]=7;
	weight[19]=7;
	weight[20]=7;
	weight[21]=7;
	weight[22]=8;
	weight[23]=8;
	weight[24]=8;
	weight[25]=8;
	weight[26]=8;
	weight[27]=9;
	weight[28]=9;
	weight[29]=9;
	weight[30]=9;
	weight[31]=10;
	weight[32]=10;
	weight[33]=10;
	weight[34]=11;
	weight[35]=11;
	weight[36]=12;
}
	
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	initialize();
	vector<int> store;
	int tc;
	string word;
	getline(cin,word);
	tc=atoi(word.c_str());
	while(tc--){
		store.clear();
		getline(cin,word);
		memset(freq,0,sizeof(freq));
		for(unsigned int i=0;i<word.length();i++){
			if(word[i]!=' '){
				freq[(int)word[i]]++;
			}
		}
		for(int i=0;i<93;i++){
			if(freq[i]!=0){
				store.push_back(freq[i]);
			}
		}
		sort(store.begin(),store.end());
		vector<int>::reverse_iterator it;
		int total=0;
		int counter=1;
		for(it=store.rbegin();it!=store.rend();it++){
			total+=(*it)*(weight[counter++]);
		}
		printf("%d\n",total);
	}
	return 0;
}
