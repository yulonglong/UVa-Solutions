//Steven Kester Yuwono - UVa 11151

#include <bits/stdc++.h>
using namespace std;

string word;

int memoi[1010][1010];

int dp(int l, int r){
	if (l==r){
		return 1;
	}
	if (l+1==r){
		if(word[l]==word[r]){
			return 2;
		}
		else{
			return 1;
		}
	}
	if(memoi[l][r]!= -1){
		return memoi[l][r];
	}
	
	if(word[l]==word[r]){
		return memoi[l][r] = 2 + dp(l + 1, r - 1);
	}
	else{
		return memoi[l][r] = max(dp(l, r - 1), dp(l + 1, r));
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	
	int tc;
	getline(cin,word);
	tc = atoi(word.c_str());
	while(tc--){
		getline(cin,word);
		if(word.length()==0){
			cout << "0" << endl;
			continue;
		}
		memset(memoi,-1,sizeof(memoi));
		int ans = dp(0,word.length()-1);
		cout << ans << endl;
	}
	return 0;
}
