//uva 146
#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	char word[51];
	while (scanf("%s", word) &&(word[0]!='#')){
		string temp = word;
		int length = temp.length();
		bool valid=false;
		if (next_permutation(word,word+length)){
			printf("%s\n",word);
			valid=true;
		}
		if(!valid){
			printf("No Successor\n");
		}
	}
	return 0;
}
