// Steven Kester Yuwono - UVa 12485
#include <cstdio>

int note[10010];

int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		int total = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&note[i]);
			total += note[i];
		}
		int average = total/n;

		int negative = 0;
		int positive = 0;
		for(int i=0;i<n;i++){
			if (average > note[i]) {
				positive += average-note[i];
			}
			else if (average < note[i]){
				negative += note[i]-average;
			}
		}
		if (positive != negative) printf("-1\n");
		else printf("%d\n",(positive+negative)/2+1);
	}
	return 0;
}
