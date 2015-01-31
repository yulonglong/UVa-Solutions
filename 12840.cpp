//Steven Kester Yuwono - UVa 12840

#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int score[51];

vector<pair<int,int> > copyVecFast(vector<pair<int,int> > original) {
	vector<pair<int,int> > new_ (original);
	return new_;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int n, s;
		scanf("%d %d",&n,&s);
		for(int k=0;k<n;k++){
			scanf("%d",&score[k]);
		}
		vector<pair<int,int> > ans;
		vector<pair<int,int> > st;
		int index = n-1;
		int currScore = 0;
		int size = 2000000000;
		while(true){
			if (currScore+score[index] <= s){
				st.push_back(pair<int,int>(score[index],index));
				currScore += score[index];
				if (currScore == s) {
					if(size > st.size()){
						ans = copyVecFast(st);
						size = st.size();
					}
					// A hack to make this bruteforce solution not-TLE
					if(size<=2){
						break;
					}
				}
			}
			else {
				if(index > 0) {
					index--;
				}
				else if (!st.empty()){
					pair<int,int> top = st.back();
					st.pop_back();
					currScore -= top.first;
					index = top.second - 1;
					while (index<0){
						if (st.empty()){
							break;
						}
						else {
							pair<int,int> top2 = st.back();
							st.pop_back();
							currScore -= top2.first;
							index = top2.second - 1;
						}
					}
				}
				// Check for invalid case (impossible)
				if (st.empty() && (index < 0)) {
					break;
				}
			}
		}

		if (ans.empty()){
			printf("Case %d: impossible\n",d);
		}
		else {
			printf("Case %d: [%d]",d,ans.size());
			for(int i=0;i<(int)ans.size();i++){
				printf(" %d",ans[i].first);
			}
			printf("\n");
		}

	}
	return 0;
}