//Steven Kester Yuwono - UVa 10242

#include <cstdio>
#include <cmath>
#define EPS 1e-9
using namespace std;

int main(){
	double x[4], y[4];
	while (scanf(" %lf %lf ",&x[0],&y[0])==2){
		for(int i=1;i<4;i++){
			scanf(" %lf %lf ",&x[i],&y[i]);
		}
		int common[2];
		for(int i=0;i<4;i++){
			for (int j=i+1;j<4;j++){
				if ((fabs(x[i]-x[j])<EPS)&&(fabs(y[i]-y[j])<EPS)){
					common[0] = i;
					common[1] = j;
					break;
				}
			}
		}

		int uncommon[2];
		int size = 0;
		for(int i=0;i<4;i++){
			if((common[0]!=i)&&(common[1]!=i)){
				uncommon[size++] = i;
			}
		}

		double subX, subY;
		subX = x[common[0]] - x[uncommon[0]];
		subY = y[common[0]] - y[uncommon[0]];

		double ansX, ansY;
		ansX = x[uncommon[1]] - subX;
		ansY = y[uncommon[1]] - subY;

		printf("%.3f %.3f\n",ansX,ansY);
	}
	return 0;
}