#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

int LSOne(int i){
	return (i)&(-i);
}

class FenwickTree{
private:
	vi ft;
public:
	FenwickTree(int n){
		ft.assign(n+1,0);
	}
	int rsq(int b){
		int sum=0;
		for(;b>0;b-=LSOne(b)){
			sum+=ft[b];
		}
		return sum;
	}
	int rsq(int a, int b){
		if(a==1){
			return rsq(b);
		}
		return rsq(b)-rsq(a-1);
	}
	void adjust(int k,int v){
		for(;k<(int)ft.size();k+=LSOne(k)){
			ft[k]+=v;
		}
	}
};


int main(){
	int N,K;
	while(scanf("%d %d",&N,&K)==2){
		FenwickTree ftNeg(N);
		FenwickTree ftZero(N);
		int tempInt;
		for(int i=1;i<=N;i++){
			scanf("%d",&tempInt);
			if(tempInt==0){
				ftZero.adjust(i,1);
			}
			else if(tempInt<0){
				ftNeg.adjust(i,1);
			}
		}
		for(int i=0;i<K;i++){
			char command;
			int I;
			int V;
			scanf(" %c %d %d", &command, &I, &V);
			if(command=='C'){
				tempInt = ftNeg.rsq(I,I);
				if(tempInt>0){
					ftNeg.adjust(I,-1);
				}
				tempInt = ftZero.rsq(I,I);
				if(tempInt>0){
					ftZero.adjust(I,-1);
				}
				if(V==0){
					ftZero.adjust(I,1);
				}
				else if(V<0){
					ftNeg.adjust(I,1);
				}
			}
			else if(command=='P'){
				tempInt=ftZero.rsq(I,V);
				if (tempInt>0){
					printf("0");
				}
				else {
					tempInt=ftNeg.rsq(I,V);
					if(tempInt%2==0){
						printf("+");
					}
					else{
						printf("-");
					}
				}
				
			}
		}
		printf("\n");
	}
	return 0;
}


