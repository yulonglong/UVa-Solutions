//Steven Kester Yuwono - UVa 11012

#include <cstdio>
#include <vector>
#include <cmath>
#define INF 2000000000
#define NINF -2000000000
using namespace std;

struct Node {
	int x;
	int y;
	int z;
	Node(int newX, int newY, int newZ) : x(newX), y(newY), z(newZ) {}
};

vector<Node> cabbages;

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++) {
		cabbages.clear();
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			cabbages.push_back(Node(x,y,z));
		}
		
		int maxDist = NINF;
		// permutating all min/max conditions, bitmask
		// 000, 001, 010, 011, 100, 101, 110, 111
		for(int mask=0;mask<(1<<3);mask++){
			int maxSum = NINF;
			int minSum = INF;
			for(int j=0;j<n;j++){
				int sum = 0;
		
				if((1<<0) & mask) sum += cabbages[j].x;
				else sum -= cabbages[j].x;

				if((1<<1) & mask) sum += cabbages[j].y;
				else sum -= cabbages[j].y;

				if((1<<2) & mask) sum += cabbages[j].z;
				else sum -= cabbages[j].z;

				minSum = min(minSum,sum);
				maxSum = max(maxSum,sum);
			}
			maxDist = max(maxDist, maxSum-minSum);
		}

		printf("Case #%d: %d\n",d,maxDist);
	}
	return 0;
}