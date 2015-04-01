// Steven Kester Yuwono - UVa 11512
// Suffix Array

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
char P[MAX_N];
int m;

int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];

bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }

void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =
			(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;
} }

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		Phi[SA[i]] = SA[i-1];
	for (i = L = 0; i < n; i++) {
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }
		while (T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

ii stringMatching() {
	int lo = 0, hi = n-1, mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res >= 0) hi = mid;
		else          lo = mid + 1;
	}
	if (strncmp(T + SA[lo], P, m) != 0) return ii(-1, -1);
	ii ans; ans.first = lo;
	lo = 0; hi = n - 1; mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res > 0) hi = mid;
		else         lo = mid + 1;
	}
	if (strncmp(T + SA[hi], P, m) != 0) hi--;
	ans.second = hi;
	return ans;
}

ii LRS() {
	int i, idx = 0, maxLCP = -1;
	for (i = 1; i < n; i++)
		if (LCP[i] > maxLCP) {
			maxLCP = LCP[i], idx = i;
		}
	return ii(maxLCP, idx);
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

ii LCS() {
	int i, idx = 0, maxLCP = -1;
	for (i = 1; i < n; i++)
		if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP)
			maxLCP = LCP[i], idx = i;
	return ii(maxLCP, idx);
}

int main() {
	int tc; scanf("%d",&tc);
	while(tc--) {
		scanf("%s",T);
		n = (int)strlen(T);
		T[n++] = '$';

		constructSA();
		computeLCP();

		ii ans = LRS();
		memset(P,0,sizeof(P));
		strncpy(P, T + SA[ans.second], ans.first);
		m = strlen(P);

		if(ans.first == 0){
			printf("No repetitions found!\n");
		}
		else {
			ii p = stringMatching();
			printf("%s %d\n",P,p.second-p.first+1);
		}
	}

	return 0;
}
