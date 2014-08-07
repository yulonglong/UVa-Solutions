#include <bits/stdc++.h>
using namespace std;

int cal[4000];

int main(){
	//freopen("in.txt","r",stdin);
	int tc;
	cin >> tc;
	while(tc--){
		memset(cal,0,sizeof(cal));
		int days;
		cin >> days;
		//cout << days << endl;
		int numParty;
		cin >> numParty;
		//cout << numParty  << endl;
		for(int i=0;i<numParty;i++){
			int temp;
			cin >> temp;
			//cout << temp  << endl;
			for(int j=temp;j<=days;j=j+temp){
				cal[j]=1;
				if((j%7==6)||(j%7==0)){
					cal[j]=0;
				}
			}
		}
		for(int i=0;i<numParty;i++){
		
		}
		int total=0;
		for(int j=1;j<=days;j++){
			total+=cal[j];
		}
		cout << total << endl;
			
	}
	return 0;
}
