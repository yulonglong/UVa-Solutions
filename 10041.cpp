//Steven Kester Yuwono - UVa 10041

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		vector<int> store;
		for(int d = 0; d < n; d++){
			int temp;
			scanf("%d", &temp);
			store.push_back(temp);
		}
		sort(store.begin(),store.end());
		
		int size = store.size();
		int median;
		if(size%2==1){
			median = store[size/2];
		}
		else{
			median = (store[size/2]+store[(size/2)-1]) / 2;
		}

		int totalDist = 0;
		for(int i=0;i<size;i++){
			totalDist = totalDist + abs(median-store[i]);
		}
		//printf("Median : %d\n",median);
		printf("%d\n",totalDist);
	}
	return 0;
}