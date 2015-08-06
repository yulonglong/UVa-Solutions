// Steven Kester Yuwono - UVa 11526
#include <cstdio>
#include <cmath>

long long H(int n){
	if(n<=0) return 0;
	long long sum = 0;
	int root = floor(sqrt(n));
	int last = n;
	for (int i = 0; i < root; i++) {
		int temp = n/(i+1);
		sum += temp + i*(last-temp);
		last = temp;
	}
	if (n/root > root) return sum+root;
	return sum;
}

int main(){
	int tc,n;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d",&n);
		printf("%lld\n", H(n));
	}
	return 0;
}
