//Steven Kester Yuwono - UVa 10882

#include <cstdio>
#include <algorithm>
using namespace std;

int minimum(int a, int b, int c){
	return min(a,min(b,c));
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		int x, y, z;
		scanf("%d %d %d",&x, &y, &z);
		int lower, higher;
		higher = minimum(x,y,z);
		if(x+y+z <=100){
			lower = 0;
		}
		else {
			lower = (x+y+z-99)/2;
		}
		if ((lower<0)||(lower>higher)){
			printf("Case #%d: The records are faulty.\n", d);
		}
		else{
			printf("Case #%d: Between %d and %d times.\n", d, lower, higher);
		}
	}
	return 0;
}