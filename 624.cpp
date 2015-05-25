// Steven Kester Yuwono - UVa 624

#include <cstdio>
#include <vector>
using namespace std;

int ans = -1e9;
vector<int> ansNum;

void findTime(int limit, int index, int current, vector<int> &track, vector<int> &taken) {
	if (index == track.size()) {
		if (current > ans) {
			ans = current;
			ansNum.clear();
			for(int i=0;i<taken.size();i++){
				ansNum.push_back(taken[i]);
			}
		}
		return;
	}
	if (current + track[index] <= limit) {
		taken.push_back(track[index]);
		findTime(limit,index+1,current+track[index],track,taken);
		taken.pop_back();
	}
	findTime(limit,index+1,current,track,taken);
	return;
}

int main() {
	int limit;
	while(scanf("%d",&limit)==1) {
		ans = -1e9;
		ansNum.clear();
		int n; scanf("%d",&n);
		vector<int> track;
		for(int i=0;i<n;i++){
			int temp; scanf("%d",&temp);
			track.push_back(temp);
		}
		vector<int> dummyTaken;
		findTime(limit,0,0,track,dummyTaken);

		for(int i=0;i<(int)ansNum.size();i++){
			printf("%d ",ansNum[i]);
		}
		printf("sum:%d\n",ans);
	}
	return 0;
}
