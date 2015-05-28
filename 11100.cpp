// Steven Kester Yuwono - UVa 11100

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10100
using namespace std;

int store[MAX];

int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		memset(store,0,sizeof(store));
		for(int i=0;i<n;i++){
			scanf("%d",&store[i]);
		}
		sort(store,store+n);

		// Find the maximum number of same sized bags
		int maxLug = -1;
		int curr = 1;
		for(int i=0;i<n;i++){
			if(store[i] == store[i+1]) {
				curr++;
				continue;
			}
			if (curr > maxLug) maxLug = curr;
			curr = 1;
		}

		// Output with the max num of same sized bags interval
		printf("%d\n",maxLug);
		for (int i=0;i<maxLug;i++){
			bool first = true;
			for (int j=i;j<n;j+=maxLug) {
				if (first) first = false;
				else  printf(" ");
				printf("%d",store[j]);
			}
			printf("\n");
		}
	}
	return 0;
}