// Steven Kester Yuwono - UVa 10370

#include <cstdio>
using namespace std;

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int n;
		scanf("%d",&n);
		int score[1001];
		for(int i=0;i<n;i++){
			scanf("%d",&score[i]);
		}
		double average = 0;
		for(int i=0;i<n;i++){
			average += (double)score[i];
		}
		average /= (double)n;
		int count = 0;
		for(int i=0;i<n;i++){
			if(score[i] > average) {
				count++;
			}
		}
		printf("%.3f%%\n",(double)count*100.0/(double)n);
	}
	return 0;
}