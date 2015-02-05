// Steven Kester Yuwono - UVa 11259

#include <cstdio>
#include <cstring>
using namespace std;

int c[4], d[4], q, v;
long long memo[100100];

void init(){
	memset(memo,0,sizeof(memo));
	memo[0] = 1;
	for(int i=0;i<4;i++) {
		for(int j=c[i];j<=100100;j++) {
			memo[j] += memo[j-c[i]];
		}
	}
}

long long dp() {
	long long ans = 0;
	// bit-wise all 4 bits permutation from 0000 to 1111
	for(int i = 0;i < 16;i++){
		int tempV = v;
		int f = 1;
		for(int j = 0;j < 4;j++){
			if(i&(1<<j)){
				f = -f;
				tempV -= (d[j]+1) * c[j];
			}
		}
		if(tempV >= 0)  {
			ans += f * memo[tempV];
		}
	}
	return ans;
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--){
		
		for(int i=0;i<4;i++){
			scanf("%d",&c[i]);
		}

		init();

		scanf("%d",&q);
		for(int j=0;j<q;j++) {
			for(int i=0;i<4;i++){
				scanf("%d",&d[i]);
			}
			scanf("%d",&v);
			printf("%lld\n",dp());
		}
	}
	return 0;
}