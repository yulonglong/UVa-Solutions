//Steven Kester Yuwono - UVa 10696
//Memoization

#include <cstdio>
#include <cstring>
#define MAX 1000100
using namespace std;

int memo[MAX];

int f91(int N){
	if(memo[N]!=-1){
		return memo[N];
	}
	if(N<=100){
		return memo[N] = f91(f91(N+11));
	}
	return memo[N] = N-10;
}

void init(){
	memset(memo,-1,sizeof(memo));
	for(int i=0;i<=1000010;i++){
		if(memo[i]==-1){
			f91(i);
		}
	}
}

int main(){
	init();
	int input;
	while(scanf("%d",&input)&&(input!=0)){
		printf("f91(%d) = %d\n",input,memo[input]);
	}
	return 0;
}