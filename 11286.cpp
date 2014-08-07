//uva 11286
#include <bits/stdc++.h>
using namespace std;

int combi[5];
map<string,int> store;
map<string,int>::iterator it;

string convertToString(){
	string result;
	char buffer[500];
	sprintf(buffer,"%d%d%d%d%d",combi[0],combi[1],combi[2],combi[3],combi[4]);
	result = buffer;
	return result;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in2.txt","r",stdin);
	#endif
	int n;
	cin >> n;
	while(n!=0){
		store.clear();
		for(int i=0;i<n;i++){
			cin >> combi[0] >> combi[1] >> combi[2] >> combi[3] >> combi[4];
			sort(combi,combi+5);
			string combiStr = convertToString();
			it = store.find(combiStr);
			if(it==store.end()){
				store.insert(pair<string,int>(combiStr,1));
			}
			else{
				it->second +=1;
			}
		}
		
		int maximum = -1;
		for(it=store.begin();it!=store.end();it++){
			if (it->second > maximum){
				maximum = it->second;
			}
		}
		
		int counter=0;
		for(it=store.begin();it!=store.end();it++){
			if (it->second == maximum){
				counter = counter + maximum;
			}
		}
		
		cout << counter << endl;
		
		cin >> n;
	}
	return 0;
}
