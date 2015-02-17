// Steven Kester Yuwono - UVa 10118

#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 41

using namespace std;

int pile[MAXN][4];
int memo[MAXN][MAXN][MAXN][MAXN];
int top[4];
int n;

int dp(int pocket, bool hasColor[]) {
	int checkMemo = memo[top[0]][top[1]][top[2]][top[3]];
	if (checkMemo != -1) {
		return checkMemo;
	}

	if (pocket == 5){
		memo[top[0]][top[1]][top[2]][top[3]] = 0;
		return 0;
	}

	int ans = 0;
	for(int i=0;i<4;i++){
		if (top[i] == n) {
			continue;
		}
		int currCandy = pile[top[i]][i];
		top[i]++;
		if (hasColor[currCandy]) {
			hasColor[currCandy] = false;
			ans = max(ans,dp(pocket-1,hasColor) + 1);
			hasColor[currCandy] = true;
		}
		else {
			hasColor[currCandy] = true;
			ans = max(ans,dp(pocket+1,hasColor));
			hasColor[currCandy] = false;
		}
		top[i]--;
	}
	memo[top[0]][top[1]][top[2]][top[3]] = ans;
	return ans;
}

int main() {
	while ((scanf("%d",&n)==1)&&(n>0)) {
		for(int i=0;i<n;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&pile[i][j]);
			}
		}
		bool hasColor[21];

		memset(memo,-1,sizeof(memo));
		memset(top,0,sizeof(top));
		memset(hasColor,0,sizeof(hasColor));
		
		printf("%d\n",dp(0,hasColor));
	}
	return 0;
}