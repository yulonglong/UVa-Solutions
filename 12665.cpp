//Steven Kester Y - UVa 12665
#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int d=0;
	int lo,hi;
	while(cin >> lo >> hi){
		d++;
		int counter=0;
		int maxLoop = min(1001,hi);
		for(int i=lo;i<=maxLoop;i++){
			for(int j=lo;j<=maxLoop;j++){
				long long ans = i*i*i + j*j*j;
				if((ans/10<=hi)&&(ans/10>=lo)&&(ans%10==3)){
					counter++;
				}
			}
		}
		printf("Case %d: %d\n",d,counter);
	}
}
