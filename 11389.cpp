//uva 11389
#include <bits/stdc++.h>
using namespace std;

int start[110];
int end[110];

int main(){
	//freopen("in2.txt","r",stdin);
	int n,d,r;
	cin >> n >> d >> r;
	while(!((n==0)&&(d==0)&&(r==0))){
		
		for(int i=0;i<n;i++){
			cin >>start[i];
		}
		for(int i=0;i<n;i++){
			cin >>end[i];
		}
		sort(start,start+n);
		sort(end,end+n);
		int excess=0;
		int newN=n-1;
		for(int i=0;i<=newN;i++){
			int total = start[i]+end[newN-i];
			int diff = total - d;		
			if(diff>0){
				excess+=diff;
			}
		}
		cout << excess*r << endl;

		cin >> n >> d >> r;
	}
	return 0;
}
