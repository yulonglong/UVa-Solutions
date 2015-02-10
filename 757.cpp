// Steven Kester Yuwono - UVa 757

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 26
using namespace std;

struct Node {
	int lakeNo;
	int f;
	int d;
	int t;
	bool operator () (const Node& lhs,const Node &rhs){  
		if(lhs.f == rhs.f) {
			return (lhs.lakeNo > rhs.lakeNo);
		}
		return (lhs.f < rhs.f);  
	} 
};
Node store[MAX];

void solve(int h, int n){
	int tempTimeSpend[MAX];
	int ansTimeSpend[MAX];
	memset(ansTimeSpend,0,sizeof(ansTimeSpend));
	
	int maxFish = -1;
	for(int z=0;z<n;z++){
		memset(tempTimeSpend,0,sizeof(tempTimeSpend));

		priority_queue <Node,vector<Node>, Node> pq;
		for(int i=0;i<=z;i++){
			pq.push(store[i]);
		}
		int remainingTime = (h*60) - store[z].t;
		int currTotalFish = 0;

		while (remainingTime > 0) {
			Node currNode = pq.top();
			pq.pop();
			if(currNode.f <= 0) {
				break;
			}
			currTotalFish += currNode.f;
			currNode.f -= currNode.d;
			tempTimeSpend[currNode.lakeNo] += 5;
			remainingTime -= 5;
			pq.push(currNode);
		}
		// spend in first lake of all the remaining time
		if(remainingTime > 0){
			tempTimeSpend[0] += remainingTime;
		}
		if(currTotalFish > maxFish) {
			maxFish = currTotalFish;
			for(int i=0;i<n;i++){
				ansTimeSpend[i] = tempTimeSpend[i];
			}
		}
	}

	printf("%d",ansTimeSpend[0]);
	for(int i=1;i<n;i++){
		printf(", %d",ansTimeSpend[i]);
	}
	printf("\n");
	printf("Number of fish expected: %d\n",maxFish);
	return;
}

int main() {
	int n, h;
	int f[26], d[26], t[26];
	bool first = true;
	while ((scanf("%d",&n)==1)&&(n>0)) {

		scanf("%d",&h);
		for(int z=0;z<n;z++){
			scanf("%d",&store[z].f);
			store[z].lakeNo = z;
		}
		for(int z=0;z<n;z++){
			scanf("%d",&store[z].d);
		}
		store[0].t = 0;
		for(int z=1;z<n;z++){
			int tempTime;
			scanf("%d",&tempTime);
			store[z].t = store[z-1].t + (tempTime*5);
		}

		if (first){
			first= false;
		}
		else {
			printf("\n");
		}

		solve(h,n);
	}
	return 0;
}