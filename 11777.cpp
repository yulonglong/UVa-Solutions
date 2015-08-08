// Steven Kester Yuwono - UVa 11777
#include <cstdio>

int main() {
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int term1,term2,final,att,test1,test2,test3;
		scanf("%d %d %d %d %d %d %d",&term1,&term2,&final,&att,&test1,&test2,&test3);
		int test;
		if ((test1 <= test2) && (test1 <= test3)) test = (test2+test3)/2;
		else if ((test2 <= test1) && (test2 <= test3)) test = (test1+test3)/2;
		else if ((test3 <= test1) && (test3 <= test2)) test = (test1+test2)/2;

		int total = term1+term2+final+att+test;

		printf("Case %d: ",d);
		if (total >= 90) printf("A\n");
		else if (total >= 80) printf("B\n");
		else if (total >= 70) printf("C\n");
		else if (total >= 60) printf("D\n");
		else printf("F\n");
	}
	return 0;
}
