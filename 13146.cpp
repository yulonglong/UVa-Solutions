// UVa 13146 - Steven Kester Yuwono
// Minimum Edit Distance (Levenshtein Distance)
// Substitution, deletion, and insertion of cost 1

#include <bits/stdc++.h>
using namespace std;
#define MAX 102

int getMinimumEditDistance(string a, string b) {
	a = " " + a;
	b = " " + b;
	int memo[MAX][MAX];
	memset(memo, 0, sizeof(memo));
	for (int i = 0; i < b.length(); i++) {
		memo[0][i] = i;
	}
	for (int i = 0; i < a.length(); i++) {
		memo[i][0] = i;
	}
	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			int x = memo[i][j - 1] + 1;
			int y = memo[i - 1][j] + 1;
			int z = memo[i - 1][j - 1] + 1;
			if (a[i] == b[j]) z--;
			int d = min(x, y);
			d = min(d, z);
			memo[i][j] = d;
		}
	}
	return memo[a.length() - 1][b.length() - 1];
}

int main() {
	string line;
	getline(cin, line);
	int n = atoi(line.c_str());
	while (n--) {
		string line1, line2;
		getline(cin, line1);
		getline(cin, line2);
		cout << getMinimumEditDistance(line1, line2) << endl;
	}
	return 0;
}
