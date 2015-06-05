#include <cstdio>

int month[12];

int sumMonths(int start, int end){
	int total = 0;
	for(int i=start;i<=end;i++){
		total += month[i];
	}
	return total;
}

int main() {
	int s,d;
	while (scanf("%d %d",&s,&d)==2) {
		for(int i=0;i<12;i++) month[i] = s;
		for(int i=0;i<=7;i++){
			int five = i+4;
			int curr = i+4;
			while(sumMonths(i,five) >= 0) {
				month[curr] = -1*d;
				curr--;
			} 
		}
		int ans = sumMonths(0,11);
		if(ans<0) printf("Deficit\n");
		else printf("%d\n",ans);
	}
	return 0;
}