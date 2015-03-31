// Steven Kester Yuwono - UVa 1239

#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

int memo[MAX][MAX];

int main () {
	int tc;
	cin >> tc;
	while (tc--) {
		string word;
		int k, longest = 0;
		cin >> word >> k;
		memset(memo,0,sizeof(memo));
		for(int lower=word.length()-1; lower>=0; lower--) {
			for(int higher=lower; higher<(int)word.length(); higher++) {
				memo[lower][higher] = memo[lower+1][higher-1];
				if(word[lower] != word[higher]) memo[lower][higher]++;
				if(memo[lower][higher] <= k) longest = max(longest,higher-lower+1);
			}
		}
		cout << longest << endl;
	}
	return 0;
}