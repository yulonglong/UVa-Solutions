//uva 1180
#include <bits/stdc++.h>
using namespace std;

int main(){
	set<int> store;
	set<int>::iterator it;
	store.insert(2);
	store.insert(3);
	store.insert(5);
	store.insert(7);
	store.insert(13);
	store.insert(17);
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int d=0;
	cin>>d;
	char temp;
	while(d--){
		int p=0;
		cin>>p;
		//cout << p <<endl;
		cin>>temp;	
		it=store.find(p);
		if(it==store.end()){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
}
