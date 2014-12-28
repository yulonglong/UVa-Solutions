//Steven Kester Yuwono - UVa 11078

#include <cstdio>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int temp;
		scanf("%d",&temp);
		int currMax = temp;
		scanf("%d",&temp);
		int currDiff = currMax - temp;

		if(currMax<temp){
			currMax = temp;
		}

		for(int d = 2; d < n; d++){
			scanf("%d",&temp);
			if (currDiff < currMax - temp){
				currDiff = currMax - temp;
			}
			if (currMax < temp){
				currMax = temp;
			}
		}

		printf("%d\n",currDiff);
	}
	return 0;
}