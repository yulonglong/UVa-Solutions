#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T[110];
int P[110];
int S[110];
int memo[30100][110];
int profit[30100][110];


int main(){
	int first=1;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		if(first==1){
			first=0;
		}
		else{
			printf("\n");
		}
		memset(memo,0,sizeof(memo)) ;
		memset(profit,0,sizeof(profit));  
		int N,K,tMax;
		scanf("%d %d %d",&N,&K,&tMax);
		
		for(int i=0;i<N;i++){
			scanf("%d",&T[i]);
		}
		for(int i=0;i<N;i++){
			scanf("%d",&P[i]);
		}
		for(int i=0;i<N;i++){
			scanf("%d",&S[i]);
			profit[T[i]][S[i]]+=P[i];
		}
		for(int i=0;i<tMax;i++){
			int minLoop=min(i,K);
			for(int j=0;j<=minLoop;j++){
				if(j>0){
					memo[i+1][j-1]=max(memo[i+1][j-1],memo[i][j]+profit[i+1][j-1]);
				}
				memo[i+1][j]=max(memo[i+1][j],memo[i][j]+profit[i+1][j]);
				memo[i+1][j+1]=max(memo[i+1][j+1],memo[i][j]+profit[i+1][j+1]);
			}
		}
		int maximum=0;
		for(int i=0;i<=K;i++){
			maximum=max(maximum,memo[tMax][i]);
		}
		printf("%d\n",maximum);
	}
	return 0;
}
