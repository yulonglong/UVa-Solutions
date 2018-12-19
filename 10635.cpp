// Steven Kester Yuwono - UVa 10635
// Longest Common Subsequence -> Longest Increasing Subsequence (NlogN) (N=250*250)

#include <bits/stdc++.h>
using namespace std;
#define MAX 251
#define INF 2e9
typedef pair<int,int> ii;

int memo[MAX*MAX];
int ar[MAX*MAX];

int main() {
	int t; scanf("%d",&t);
	for (int tc=1;tc<=t;tc++) {
		memset(memo,0,sizeof(memo));
		memset(ar,-1,sizeof(ar));
		int n,p,q;	scanf("%d %d %d",&n,&p,&q);
		for (int i=0;i<=p;i++) {
			int val; scanf("%d",&val);
			ar[val] = i;
		}
		vector<int> seq;
		for (int i=0;i<=q;i++) {
			int val; scanf("%d",&val);
			// If this item exists in A, record the index sequence
			if (ar[val] != -1)
				seq.push_back(ar[val]);
		}
		
		// LIS (Longest Increasing Subsequence) 
		// N log N
		vector<int> ans; // Keep the sequence of possible answers here
		ans.assign(seq.size(),INF);
		int ansMax = 0;
		for (int idx : seq) {
			// perform binary search (log N) and optimize longest sequence
			int ansIdx = lower_bound(ans.begin(), ans.end(), idx) - ans.begin(); 
			ans[ansIdx] = idx;
			ansMax = max(ansMax, ansIdx);
		}
		
		printf("Case %d: %d\n", tc, ansMax+1);
	}
	return 0;
}
