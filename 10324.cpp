//uva 10324
#include <bits/stdc++.h>
using namespace std;

bool isSame(char input[],int begin,int end){
	if(begin==end){
		return true;
	}
	for(int i=begin;i<end;i++){
		if(input[i]^input[i+1]){
			return false;
		}
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	char word[1000010];
	int counter=0;
	int n;
	while (scanf("%s\n%d", word, &n)==2) {
		counter++;
		printf("Case %d:\n", counter);
		for(int i=0;i<n;i++){
			int a, b;
			scanf("%d%d\n", &a, &b);
			int low = min(a,b);
			int high = max(a,b);
			if(isSame(word,low,high)){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
	}
	return 0;
}
