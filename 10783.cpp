//Steven Kester Yuwono - UVa 10783

#include <cstdio>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	for(int d=1; d<=tc; d++){
		int lower, higher;
		scanf("%d",&lower);
		scanf("%d",&higher);
		if(lower%2 == 0){
			lower++;
		}
		if(higher%2 == 0){
			higher--;
		}
		int n = ((higher - lower) / 2) + 1;
		int ans = (lower+higher) * n / 2;
		printf("Case %d: %d\n",d,ans);
	}
	return 0;
}