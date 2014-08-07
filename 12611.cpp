//Steven Kester Yuwono - UVa 12611

#include <cstdio>
using namespace std;

int main(){
	int tc,r;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		scanf("%d",&r);
		int length = r*5;
		int width = length*6/10;
		int widthC = width/2;
		int lenLow = length*45/100;
		int lenHi = length*55/100;
		printf("Case %d:\n",d);
		printf("-%d %d\n",lenLow,widthC);
		printf("%d %d\n",lenHi,widthC);
		printf("%d -%d\n",lenHi,widthC);
		printf("-%d -%d\n",lenLow,widthC);
	}
	return 0;
}
