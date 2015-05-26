// Steven Kester Yuwono - UVa 10487

#include <cstdio>
#include <cmath>
#define MAX 1010
using namespace std;

int store[MAX];

int getClosestNum(int n, int num) {
	int closestNum = -1;
	int difference = 1e9;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int currDiff = abs(num - (store[i] + store[j]));
			if(currDiff < difference) {
				difference = currDiff;
				closestNum = store[i] + store[j];
			}
		}
	}
	return closestNum;
}

int main() {
	int caseNum = 1;
	int n;
	while ((scanf("%d",&n)==1) && (n > 0)) {
		printf("Case %d:\n",caseNum++);
		for(int i=0;i<n;i++) {
			scanf("%d",&store[i]);
		}
		int m; scanf("%d",&m);
		for(int i=0;i<m;i++){
			int num; scanf("%d",&num);
			int ans = getClosestNum(n,num);
			printf("Closest sum to %d is %d.\n",num,ans);
		}
	}
	return 0;
}