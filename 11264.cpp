//uva 11264

#include <bits/stdc++.h>
using namespace std;

int coins[1010];

int main(){
    //freopen("in2.txt","r",stdin);
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> coins[i];
		}
		sort(coins,coins+n);
		
		int counter=1;
		int sum = coins[0];
		for(int i=1;i<n;i++){
			if(i==n-1){
				counter++;
				break;
			}
			if(sum+coins[i]<coins[i+1]){
				counter++;
				sum = sum + coins[i];
			}
		}
		
		cout << counter << endl;
		
	}
	return 0;
}
