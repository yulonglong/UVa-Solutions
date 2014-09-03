//Steven Kester Yuwono - UVa 11658
//Bottom-up DP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
using namespace std;

int memo[10002];
int stock[102];

int main(){
	int n,x;
	while((cin >> n >> x)&&(!((n==0)&&(x==0)))){
		string temp;
		memset(memo,0,sizeof(memo));
		memset(stock,0,sizeof(stock));

		for(int i=1;i<=n;i++){
			int first;
			int second;
			scanf("%d.%d", &first, &second);
			int num = (first*100)+second;
			stock[i]=num;
		}

		memo[stock[x]]=1;

		//bottom-up DP
		for(int i=1;i<=n;i++){
			if(i==x){
				continue;
			}
			for(int j=10000; j>=stock[i]; j--){
	            if (memo[j-stock[i]]==1){
	                memo[j] = 1;
	       		}
	       	}
		}

		//get result closest to 50.01%
		int totalShare=0;
		for(int i=5001;i<=10000;i++){
			if(memo[i]==1){
				totalShare = i;
				break;
			}
		}
		int ownShare = stock[x];
		double ans = 100.0*(double)ownShare/(double)totalShare;
		printf("%.2f\n",ans);

	}
}