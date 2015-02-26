// Steven Kester Yuwono - UVa 12826

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int r1,c1,r2,c2,r3,c3;

int smallestDist() {
	int rDiff = abs(r1-r2);
	int cDiff = abs(c1-c2);
	int distance = (rDiff>cDiff)? rDiff : cDiff;
	// If move purely Diagonal
	if ((rDiff == cDiff) && (abs(r3-r2) == abs(c3-c2))){
		bool r1Biggerr2 = (r1<r2)? false : true;
		bool c1Biggerr2 = (c1<c2)? false : true;
		bool r1Biggerr3 = (r1<r3)? false : true;
		bool c1Biggerr3 = (c1<c3)? false : true;
		bool r3Biggerr2 = (r3<r2)? false : true;
		bool c3Biggerr2 = (c3<c2)? false : true;
		// Check whether it is blocked
		if(r1Biggerr2) {
			if ( (r1Biggerr3) && (r3Biggerr2)) {
				if(c1Biggerr2){
					if ((c1Biggerr3) && (c3Biggerr2)) {
						return distance + 1;
					}
				}
				else {
					if ((!c1Biggerr3) && (!c3Biggerr2)) {
						return distance + 1;
					}
				}
			}
		}
		else {
			if( (!r1Biggerr3) && (!r3Biggerr2)) {
				if(c1Biggerr2){
					if ((c1Biggerr3) && (c3Biggerr2)) {
						return distance + 1;
					}
				}
				else {
					if ((!c1Biggerr3) && (!c3Biggerr2)) {
						return distance + 1;
					}
				}
			}
		}
	}
	return distance;
}

int main() {
	int tc = 1;
	while (scanf("%d %d %d %d %d %d", &r1,&c1,&r2,&c2,&r3,&c3)==6) {
		printf("Case %d: %d\n",tc++, smallestDist());
	}
	return 0;
}