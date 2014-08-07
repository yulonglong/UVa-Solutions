#include <cstdio>
using namespace std;

int main(){
	int tc , N , K , P , pos;
	scanf("%d",&tc);
	for(int i = 1 ; i<=tc ; i++){
			scanf("%d %d %d",&N,&K,&P);
			pos = K + P;
			while(pos>N){
				pos-=N;
			}
		printf("Case %d: %d\n",i,pos);
	}
	return 0;
}
