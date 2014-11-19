//Steven Kester Yuwono - UVa 11984

#include <cstdio>
using namespace std;

double convertToC(double deg){
	return (deg - 32.0) * 5.0 / 9.0;
}

double convertToF(double deg){
	return (deg * 9.0 / 5.0) + 32.0;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int ori, add;
		scanf("%d %d",&ori,&add);
		double ans = convertToF(ori) + add;
		printf("Case %d: %.2f\n",d,convertToC(ans));
	}
	return 0;
}