// Steven Kester Yuwono - UVa 11292

#include <cstdio>
#include <algorithm>
#define MAX 20010
using namespace std;

int dragon[MAX];
int knight[MAX];

int main() {
	int n,m;
	while ((scanf("%d %d",&n,&m)==2) && (n|m)) {
		for(int i=0;i<n;i++){
			scanf("%d",&dragon[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&knight[i]);
		}
		sort(dragon,dragon+n);
		sort(knight,knight+m);

		int count = 0;
		int dragonIndex = 0;
		int knightIndex = 0;

		for(dragonIndex=0; dragonIndex<n; dragonIndex++){
			while ((knight[knightIndex] < dragon[dragonIndex]) && (knightIndex<m)){
				knightIndex++;
			}
			if(knightIndex == m) break;
			count += knight[knightIndex++];
		}
		if(dragonIndex < n) printf("Loowater is doomed!\n");
		else printf("%d\n",count);
	}
	return 0;
}