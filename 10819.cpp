// Steven Kester Yuwono - UVa 10819
// DP

#include <bits/stdc++.h>
using namespace std;
#define MAX1 15001
#define MAX2 110
#define NEGINF -2e9

int memo[MAX1][MAX2];
pair<int,int> items[MAX2];
int n;
int budget;

int dp(int spent, int state) {
	// If spent more than budget and budget is < 1800, for sure not the path we want
	if (spent > budget && budget < 1800) return NEGINF;
	// If spent more than budget + 200 including the cashback, not the path we want, cannot pay bill
	if (spent > budget + 200) return NEGINF;
	if (state == n) {
		// If it is at the end of the list, exceeded budget, but spent 2000 or less, doesnt get cashback, cannot pay bill
		if (spent > budget && spent <= 2000) return NEGINF;
		return 0;
	}
	if (memo[spent][state] >= 0) return memo[spent][state];
	int take = dp(spent + items[state].first, state + 1) + items[state].second;
	int noTake = dp(spent, state + 1);
	return memo[spent][state] = max(take,noTake);
}

int main() {
	while (scanf("%d %d", &budget, &n) == 2) {
		for (int i=0;i<n;i++) {
			int price, favor;
			scanf("%d %d", &price, &favor);
			items[i] = pair<int,int>(price,favor);
		}

		for (int i=0;i<MAX1;i++) {
			for (int j=0;j<MAX2;j++) {
				memo[i][j] = NEGINF;
			}
		}
		int ans = dp(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
