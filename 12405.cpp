//Steven Kester Yuwono - UVa 12405

#include <bits/stdc++.h>
using namespace std;

char grid[110];

int main(){
	int tc;
	cin >> tc;
	for(int d=1;d<=tc;d++){
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> grid[i];
		}
		int counter = 0;
		for(int i=0;i<n;){
			if(grid[i]=='#'){
				i++;
			}
			else{
				counter++;
				i+=3;
			}
		}
		printf("Case %d: %d\n", d, counter);
	}
	return 0;
}
