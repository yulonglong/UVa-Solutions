// Steven Kester Yuwono - UVa 11369
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int tc; scanf("%d",&tc);
	while (tc--){
		vector<int> price;
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++){
			int temp; scanf("%d",&temp);
			price.push_back(temp);
		}
		sort(price.rbegin(),price.rend());

		int total = 0;
		for(int i=2;i<n;i=i+3){
			total += price[i];
		}
		printf("%d\n",total);
	}
	return 0;
}
