//uva 11404
#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

struct word{
	string str;
	int len;
};

word memo[MAXN][MAXN];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	
	string word1, word2;
	int length;
	word a, b;

	while(getline(cin,word1)){
		length = word1.length();
		word1 = " " + word1;
		
		//reverse
		for(int i=0; i<length; ++i){
			word2 = word2 + word1[length-i];
		}
		word2 = " " + word2;
		
		//cout << "A" << word1 << "A" << endl;
		//cout << "B" << word2 << "B" << endl;
		
		for(int i=0; i<=length; i++){
			memo[0][i].str = "";
			memo[0][i].len = 0;
		}
		
		for(int i = 1; i <= length; ++i) {
			for(int j = 1; j <= length; ++j) {
				if (word1[i] == word2[j]) {
					memo[i][j].len = memo[i-1][j-1].len + 1;
					memo[i][j].str = memo[i-1][j-1].str + word1[i];

				}
				else {
					if (memo[i][j-1].len > memo[i-1][j].len) {
						memo[i][j].len = memo[i][j-1].len;
						memo[i][j].str = memo[i][j-1].str;
					}
					else if(memo[i-1][j].len > memo[i][j-1].len) {
						memo[i][j].len = memo[i-1][j].len;
						memo[i][j].str = memo[i-1][j].str;
					}
					else {
						memo[i][j].len = memo[i-1][j].len;
						//if it is lexicographically smaller
						if(memo[i-1][j].str < memo[i][j-1].str){
							memo[i][j].str = memo[i-1][j].str;
						}
						else{
							memo[i][j].str = memo[i][j-1].str;
						}
					}
				}
			}
		}

		
		string resultStr = memo[length][length].str;
		int maxLength = memo[length][length].len;

		// output
		bool n = (maxLength%2==1);
		n = !n;
		
		for(int i = 0; i < maxLength/2; i++){
			cout << resultStr[i];
		}
		for(int i = maxLength/2-n; i >= 0; i--){
			cout << resultStr[i];
		}
		cout << endl;
		
		word1="";
		word2="";
	}
	return 0;
}
