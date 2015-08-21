// Steven Kester Yuwono - UVa 11850
#include <cstdio>
#include <algorithm>
using namespace std;

int city[1455];

int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		for(int i=0;i<n;i++){
			scanf("%d",&city[i]);
		}
		sort(city,city+n);
		bool possible = true;
		for(int i=1;i<n;i++){
			if (city[i]-city[i-1]>200) {
				possible = false;
				break;
			}
		}
		if ((1422-city[n-1])*2 > 200) possible = false;
		if (possible) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
