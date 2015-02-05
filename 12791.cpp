// Steven Kester Yuwono - UVa 12791

#include <cstdio>
using namespace std;

int main() {
	int x,y;
	while (scanf("%d %d",&x,&y)==2) {
		int diff = y-x;
		int ans = y/diff;
		if(y%diff != 0) {
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}