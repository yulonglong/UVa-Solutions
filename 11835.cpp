//Steven Kester Yuwono - UVa 11835

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 110
using namespace std;

int order[MAX][MAX];
int score[MAX];

int main(){
	int G, P;
	cin >> G >> P ;
	while(!((G==0)&&(P==0))){
		memset(order,0,sizeof(order));
		memset(score,0,sizeof(score));
		for(int i=0;i<G;i++){
			for (int j=1;j<=P;j++){
				int position;
				cin >> position;
				order[i][position-1] = j;
			}
		}
		int tc;
		cin >> tc;
		for(int z=0;z<tc;z++){
			memset(score,0,sizeof(score));
			int numScore;
			cin >> numScore;
			for(int i=0;i<numScore;i++){
				int currScore;
				cin >> currScore;
				for(int j=0;j<G;j++){
					score[order[j][i]] += currScore;
				}
			}
			vector<int> ans;
			int max = -1;
			for(int i=1;i<=P;i++){
				if(max<score[i]){
					ans.clear();
					max = score[i];
					ans.push_back(i);
				}
				else if(max==score[i]){
					ans.push_back(i);
				}
			}
			cout << ans[0];
			for(int i=1;i<(int)ans.size();i++){
				cout << " " << ans[i];
			}
			cout << endl;
		}
		cin >> G >> P;
	}
	return 0;
}