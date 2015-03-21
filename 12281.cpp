// Steven Kester Yuwono - UVa 12281

#include <cstdio>
using namespace std;

long long fib[50];

void initFib() {
	fib[0] = 1;
	fib[1] = 2;
	for(int i=2;i<50;i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
}

int main (){
	initFib();
	int tc;
	scanf("%d",&tc);
	for (int d=1;d<=tc;d++) {
		int n;
		scanf("%d",&n);

		long long ans = 1;
		for(int k=0;k<n;k++) {
			int x;
			scanf("%d",&x);
			int count = 0;
			for(int i=49;i>=0;i--) {
				if(x >= fib[i]) {
					x = x-fib[i];
					count++;
				}
				if(x == 0){
					break;
				}
			}
			ans = ans * count;
		}
		printf("Case %d: %lld\n",d,ans);
	}
	return 0;
}