// Steven Kester Yuwono - UVa 524

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector< vector<int> > ans;

bool isPrime(int number) {
	for (int i=2; i<number; i++) {
		if (number % i == 0) return false;
	}
	return true;	
}

void choose(int curr[], bool visited[], int index) {
	if(index == 1){
		visited[1] = true;
		curr[1] = 1;
		choose(curr,visited,index+1);
		visited[1] = false;
	}
	else {
		for(int i=2;i<=n;i++){
			if(visited[i]) continue;
			if (index < n) {
				if (isPrime(i+curr[index-1])) {
					visited[i] = true;
					curr[index] = i;
					choose(curr,visited,index+1);
					visited[i] = false;
				}
			}
			else if (index == n) {
				if ((isPrime(i+curr[index-1])) && (isPrime(i+curr[1]))) {
					curr[index] = i;
					vector<int> temp;
					for(int j=1;j<=n;j++){
						temp.push_back(curr[j]);
					}
					ans.push_back(temp);
				}
			}
		}
	}
}

int main() {
	int tc = 1;
	while (scanf("%d",&n)==1) {
		ans.clear();
		bool visited[17]; int num[17];
		memset(visited,false,sizeof(visited));
		memset(num,0,sizeof(num));

		choose(num,visited,1);

		if(tc > 1) printf("\n");
		printf("Case %d:\n",tc++);

		for(int i=0;i<(int)ans.size();i++) {
			for(int j=0;j<(int)ans[i].size();j++) {
				if (j>0) {
					printf(" %d",ans[i][j]);
				}
				else {
					printf("%d",ans[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}