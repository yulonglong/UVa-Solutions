// Steven Kester Yuwono - UVa 1605

#include <cstdio>

int main () {
	int n;
	while (scanf("%d",&n) == 1) {
		printf("2 %d %d\n",n,n);
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				char ans = j < 26? j + 'A' : j-26 + 'a';
				printf("%c",ans);
			}
			printf("\n");
		}
		printf("\n");

		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				char ans = i < 26? i + 'A' : i-26 + 'a';
				printf("%c",ans);
			}
			printf("\n");
		}
	}
	return 0;
}