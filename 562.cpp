//Steven Kester Yuwono - UVa 562
//Bottom-up Dynamic Programming (straight forward DP)

#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 102
#define MEMOMAX 51000
using namespace std;

int memo[MAX][MEMOMAX];
int coinValue[MAX];

int main(){
	int n;
	cin >> n;

	for(int d=0;d<n;d++){
		//reset the table
		memset(memo,0,sizeof(memo));
		memset(coinValue,0,sizeof(coinValue));

		int m;
		cin >> m;
		int totalValue = 0;

		for(int i=0;i<m;i++){
			cin >> coinValue[i];
			totalValue += coinValue[i];
		}

		int idealValue = totalValue/2;
		//bottom up DP, get money as close as idealValue but not exceeding idealValue
		memo[0][0] = 1;
		for(int i=0;i<m;i++){
			for(int j=0;j<idealValue;j++){
				if(memo[i][j]==1){
					//dont take the coin
					memo[i+1][j] = 1;
					//if taking the coin does not exceed the idealValue, then take it
					if(j+coinValue[i]<=idealValue){
						memo[i+1][j+coinValue[i]] = 1;
					}
				}
			}
		}

		int moneyObtained = 0;
		for(int j=idealValue;j>=0;j--){
			//if the state is true, means there is a path to get that amount of money
			if(memo[m][j] == 1){
				moneyObtained = j;
				break;
			}
		}

		//output the difference 
		int moneyObtainedSecond = abs(totalValue-moneyObtained);
		cout << abs(moneyObtainedSecond-moneyObtained) << endl;
	}

	return 0;
}