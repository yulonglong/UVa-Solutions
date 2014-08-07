//uva 119
#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
map<int,string> m2;
map<string,int>::iterator it;
map<int,string>::iterator it2;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int valid=false;
	int n;
	while(cin >> n){
		m.clear();
		m2.clear();
		int balance[11];
		memset(balance,0,sizeof(balance));
		for(int i=0;i<n;i++){
			string name;
			cin >> name;
			m.insert(pair<string,int>(name, i));
			m2.insert(pair<int,string>(i, name));
		}
		
		for(int i=0;i<n;i++){
			
			string giver;
			cin >> giver;
			int amount;
			cin >> amount;
			int num;
			cin >> num;
			if(num==0){
				continue;
			}
			
			it=m.find(giver);
			int giverInt = it->second;
			//cout << giverInt << endl;
			
			amount = amount - (amount%num);
			balance[giverInt] = balance[giverInt] - amount;
		
				
			amount=amount/num;
			
			for(int j=0;j<num;j++){
				string receiver;
				cin >> receiver;
				it=m.find(receiver);
				int receiverInt = it->second;
				balance[receiverInt] = balance[receiverInt]+amount;
			}
		}
		
		if(valid){
			cout << endl;
		}
		
		int counter=0;
		for(it2=m2.begin();it2!=m2.end();it2++){
			cout << it2->second << " " << balance[counter++] << endl;
		}
		if(!valid){
			valid=true;
		}
	}
	return 0;
}
