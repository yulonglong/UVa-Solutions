// Steven Kester Yuwono - UVa 1235
// Minimum Spanning Tree - Prim's

#include <bits/stdc++.h>
using namespace std;
#define MAX 502

int calculateDistance(string a, string b) {
	int total = 0;
	int aInt = atoi(a.c_str());
	int bInt = atoi(b.c_str());
	for (int i=0;i<4;i++) {
		int aq = aInt % 10;
		aInt = aInt / 10;
		int bq = bInt % 10;
		bInt = bInt / 10;
		int diff = 0;
		if (bq < aq) diff = min(aq-bq, bq+10-aq);
		if (aq < bq) diff = min(bq-aq, aq+10-bq);
		total += diff;
	}
	return total;
}

struct Node {
	int cost;
	int vertex;
	bool operator () (const Node &lhs, const Node &rhs) {
		return lhs.cost > rhs.cost;
	}
};

set<int>::iterator iter;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<string> keys;
		int adjMatrix[MAX][MAX];
		memset(adjMatrix, 0, sizeof(adjMatrix));
		set<int> mst;
		set<int> original;
		for (int i=0;i<n;i++){
			char keyArr[4]; scanf("%s",&keyArr[0]);
			string key = keyArr;
			keys.push_back(key);
		}
		for (int i=0;i<n;i++){
			for (int j=i;j<n;j++) {
				int dist = calculateDistance(keys[i],keys[j]);
				adjMatrix[i][j] = dist;
				adjMatrix[j][i] = dist;
			}
			original.insert(i);
		}

		// Uncomment for debugging
		// for (int i=0;i<n;i++){
		// 	for (int j=0;j<n;j++) {
		// 		cout << adjMatrix[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		// Start prim's algorithm
		// Note that we start from 0000 but we cannot go back (JUMP) to 0000
		int totalCost = 0;
		priority_queue<Node, vector<Node>, Node> pq;
		
		// Getting the first node from 0000
		Node firstNode; firstNode.cost = 2000000000; firstNode.vertex = -1;
		for (int i=0;i<n;i++){
			int dist = calculateDistance("0000", keys[i]);
			if (dist < firstNode.cost) {
				firstNode.cost = dist;
				firstNode.vertex = i;
			}
		}
		original.erase(firstNode.vertex);
		pq.push(firstNode);
		
		// Traversal
		while (mst.size() < n) {
			int currVertex = pq.top().vertex;
			int cost = pq.top().cost;
			pq.pop();
			
			iter = mst.find(currVertex);
			if (iter != mst.end()) continue;

			mst.insert(currVertex);
			totalCost += cost;

			for (iter = original.begin(); iter != original.end(); iter++) {
				Node curr;
				curr.vertex = *iter;
				curr.cost = adjMatrix[currVertex][*iter];
				pq.push(curr);
			}
		}
		printf("%d\n", totalCost);
	}

	return 0;
}
