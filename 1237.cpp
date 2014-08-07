//Steven Kester Yuwono - UVa 1237

#include <bits/stdc++.h>
using namespace std;

string db[10010];
int low[10010];
int high[10010];

int main(){
	//freopen("in2.txt","r",stdin);
	int tc;
	cin >> tc;
	for(int z=0;z<tc;z++){
		if(z!=0){
			cout << endl;
		}
		int d, q;
		cin >> d;
		for(int i=0;i<d;i++){
			cin >> db[i] >> low[i] >> high[i];
		}
		cin >> q;
		for(int i=0;i<q;i++){
			int query;
			cin >> query;
			int counter=0;
			string brand;
			for(int j=0;j<d;j++){
				if((query>=low[j])&&(query<=high[j])){
					counter++;
					brand = db[j];
				}
				if(counter>1){
					break;
				}
			}
			if(counter==1){
				cout << brand << endl;
			}
			else{
				cout << "UNDETERMINED" << endl;
			}
		}
	}
	return 0;
}
