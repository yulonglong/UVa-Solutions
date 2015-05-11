// Steven Kester Yuwono - UVa 10720

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define MAX 10010
using namespace std;

int degree[MAX];

int isOdd(int n) {
	int sum = 0;
	for(int i=0;i<n;i++) sum += degree[i];
	return (sum%2);
}

bool isInvalidElement(int n) {
	for(int i=0;i<n;i++){
		if ((degree[i] >= n)||(degree[i] < 0)) return true;
	}
	return false;
}

bool isValidConnection(int n) {
	for(int i=0;i<n;i++){
		if(i == n-1) {
			if(degree[i] != 0) return false;
			else break;
		}
		sort(degree + i, degree + n, greater<int>());
		for(int j=i+1;j<i+1+degree[i];j++){
			if(--degree[j] < 0) return false;
		}
	}
	return true;
}

int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		memset(degree,0,sizeof(degree));
		for(int i=0;i<n;i++){
			scanf("%d",&degree[i]);
		}

		if(!isInvalidElement(n) && !isOdd(n) && isValidConnection(n)){
			printf("Possible\n");
		}
		else {
			printf("Not possible\n");
		}
	}

	return 0;
}