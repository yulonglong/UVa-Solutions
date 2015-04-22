// Steven Kester Yuwono - UVa 11730

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define INF 2000000000
using namespace std;


vector<int> primeList;
// Get All the prime numbers from 1 to 1000 and store it in the vector above
void init() {
	bool prime[1001];
	memset(prime,true,sizeof(prime));
	for(int i=2;i<=1000;i++){
		if(prime[i]){
			for(int j=i+i;j<=1000;j+=i) {
				prime[j] = false;
			}
			primeList.push_back(i);
		}
	}
	return;
}

int bfs(int S, int T){
	bool visited[1001];
	memset(visited,false,sizeof(visited));
	queue<pair<int,int> > q;
	q.push(pair<int,int>(S,0));

	int answer = -1;

	while(!q.empty()){
		int curr = q.front().first;
		int cost = q.front().second;
		q.pop();
		if(curr >  T) continue;
		if(curr == T) {
			answer = cost;
			break;
		}
		
		for(int i=0;i<(int)primeList.size();i++){
			if(primeList[i] >= curr) break;
			if ((curr%primeList[i] == 0) && (curr+primeList[i] <= T) && (!visited[curr+primeList[i]])){
				visited[curr+primeList[i]] = true;
				q.push(pair<int,int>(curr+primeList[i],cost+1));
			}
			
		}
	}
	return answer;
}

int main() {
	init();
	int S,T, tc = 1;;
	while ((scanf("%d %d",&S,&T)==2) && (S||T)) {
		printf("Case %d: %d\n",tc++,bfs(S,T));
	}

	return 0;
}