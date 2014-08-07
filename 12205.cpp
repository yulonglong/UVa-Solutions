#include <cstdio>
using namespace std;

int main(){
	int N,M;
	while(scanf("%d %d",&N,&M), ((N!=0)&&(M!=0))){
		int start[20000];
		int end[20000];
		for(int e=0;e<N;e++){
			int a,b,c,d;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			start[e]=c;
			end[e]=c+d;
		}
	
		for(int e=0;e<M;e++){
			int sum=0;
			int c,d;
			scanf("%d %d",&c,&d);
			d=d+c;
			for(int i=0;i<N;i++){
				if((c<end[i])&&(d>start[i])){
					sum++;
				}
			}
			printf("%d\n",sum);
		}
		
		
	}
	return 0;
}
