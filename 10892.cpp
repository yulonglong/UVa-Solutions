// Steven Kester Yuwono - UVa 10892

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	while(true) {
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

int lcm(int a, int b) {
	int gcdab = gcd(a, b);
	return gcdab?(a/gcdab* b):0;
}

int main() {
	int n;
	while ((scanf("%d",&n)==1) &&(n>0)) {
		vector<int> divisor;
		int limit = (int)sqrt(n);
		for(int i=1;i<=limit;i++){
			if(n%i==0){
				divisor.push_back(i);
				if(i != n/i) divisor.push_back(n/i);
			}
		}
		int cardinality = 0;
		for(int i=0;i<(int)divisor.size();i++){
			for(int j=i;j<(int)divisor.size();j++){
				if(lcm(divisor[i],divisor[j]) == n) {
					cardinality++;
				}
			}
		}
		printf("%d %d\n",n,cardinality);
	}
	return 0;
}