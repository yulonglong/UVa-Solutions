// Steven Kester Yuwono - UVa 11517
// DP

#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define MAX2 10010
#define INF 2e9
typedef pair<int, int> ii;

int n, bill, coins[MAX], memo[MAX][MAX2];

ii bottomUpDp() {
	memset(memo,-1,sizeof(memo));
	memo[0][bill] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = bill; j >= 0; j--) {
			// if previous state with remaining amount j is possible
			if (memo[i - 1][j] >= 0) {
				// Dont use current coin
				if (memo[i][j] == -1) memo[i][j] = memo[i-1][j];
				else memo[i][j] = min(memo[i][j], memo[i - 1][j]);
				// Use current coin
				int nextRemaining = j - coins[i];
				int nextCoinCount = memo[i - 1][j] + 1;
				if (nextRemaining < 0) {
					nextCoinCount += nextRemaining * -100000;
					nextRemaining = 0;
				}
				if (memo[i][nextRemaining] == -1) memo[i][nextRemaining] = nextCoinCount;
				else memo[i][nextRemaining] = min(memo[i][nextRemaining], nextCoinCount);
			}
		}
	}

	// This is just assert
	if (memo[n][0] >= 0) {
		if (memo[n][0] >= 100000) {
			int coinCount = memo[n][0] % 1000;
			int diff = memo[n][0] / 100000;
			return ii(diff, coinCount);
		} else {
			return ii(0, memo[n][0]);
		}
	}
	// should never be reached
	return ii(0, 0);
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> bill; cin >> n;
		for (int i = 1; i <= n; i++) cin >> coins[i];
		ii ans = bottomUpDp();
		cout << bill + ans.first << " " << ans.second << endl;
	}
	return 0;
}
