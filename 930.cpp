// Steven Kester Yuwono - UVa 930
// Mathematics

#include <cstdio>
#include <cmath>

double coefficient[100];

void findRoot(double a, double b, double c, double &root1, double &root2) {
	double firstTerm = (-1*b) /(2*a);
	double secondTerm = sqrt((b*b)-(4*a*c)) /(2*a);
	root1 = firstTerm + secondTerm;
	root2 = firstTerm - secondTerm;
}

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;i++){
			scanf("%lf",&coefficient[i]);
		}
		for(int i=0;i<n-2;i++){
			double root;
			scanf("%lf",&root);
			for(int j=1;j<n-i;j++){
				coefficient[j] = coefficient[j] + (root * coefficient[j-1]);
			}
		}
		double root1,root2;
		findRoot(coefficient[0],coefficient[1],coefficient[2],root1,root2);
		printf("%.1f\n%.1f\n",root1,root2);
	}
	return 0;
}