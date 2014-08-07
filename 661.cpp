//Steven Kester Yuwono - UVa 661

#include <bits/stdc++.h>
using namespace std;

int device[21];
bool state[21];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int counter=0;
	int n,o,fuse;
	cin >> n >> o >> fuse;
	while(!((n==0)&&(o==0)&&(fuse==0))){
		counter++;
		memset(device,0,sizeof(device));
		memset(state,false,sizeof(state));
		for(int i=1;i<=n;i++){
			cin >> device[i];
		}
		int maximum = 0;
		int current = 0;
		for(int i=1;i<=o;i++){
			int index;
			cin >> index;
			if (!state[index]){
				state[index]=true;
				current=current+device[index];
				maximum=max(maximum,current);
			}
			else{
				state[index]=false;
				current=current-device[index];
			}
		}	
		cout << "Sequence " << counter << endl;
		if(maximum>fuse){
			cout << "Fuse was blown." << endl << endl;
		}
		else{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << maximum << " amperes." << endl << endl;
		}
		
		cin >> n >> o >> fuse;
	}
	return 0;
}
