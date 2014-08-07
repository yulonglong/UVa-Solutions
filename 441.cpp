//Steven Kester Yuwono - UVa 441

#include <cstdio>
using namespace std;

int main(){
	int counter=0;
	int n;
	scanf("%d", &n);
	while(n!=0){
		int S[14];
		for (int i=0;i<n;i++){
			scanf("%d", &S[i]);
		}
		if(counter>0){
			printf("\n");
		}
		counter++;
		int k= n;
		for(int a=0;a<k-5;a++){
			for(int b=a+1; b<k-4;b++){
				for(int c=b+1;c<k-3;c++){
					for(int d=c+1;d<k-2;d++){
						for(int e=d+1;e<k-1;e++){
							for(int f=e+1;f<k;f++){
								printf("%d %d %d %d %d %d\n",S[a],S[b],S[c],S[d],S[e],S[f]);
							}
						}
					}
				}
			}
		}
		scanf("%d", &n);
	}
	return 0;
}
