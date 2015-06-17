// Steven Kester Yuwono - UVa 12160

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 10010
using namespace std;

int buttons[MAX];

int bfs(int L, int U, int R) {
	bool visited[MAX];
	memset(visited,false,sizeof(visited));
	int answer = -1;
	queue<pair<int,int> > q;
	q.push(pair<int,int>(L,0));

	while (!q.empty()) {
		int curr = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (visited[curr]) continue;
		visited[curr] = true;
		if (curr == U) return cost;
		for(int i=0;i<R;i++){
			int next = (curr + buttons[i]) % 10000;
			q.push(pair<int,int>(next,cost+1));
		}
	}
	return answer;
}

int main() {
	int L,U,R;
	int tc = 1;
	while ((cin >> L >> U >> R) && (L||U||R)) {
		for(int i=0;i<R;i++) cin >> buttons[i];
		cout << "Case " << tc++ << ": ";
		int ans = bfs(L,U,R);
		if(ans == -1) cout << "Permanently Locked" << endl;
		else cout << ans << endl;
	}
	return 0;
}
