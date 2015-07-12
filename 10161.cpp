// Steven Kester Yuwono - UVa 10161

#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
	int input;
	while ((scanf("%d",&input)==1) && (input>0)) {
		int root = sqrt(input-1);
		int rsquare = root*root;
		int diff = (root+1)*(root+1) - rsquare;
		
		int x,y;
		if (input-rsquare > (diff/2+1)) {
			x = 1 + (diff-(input-rsquare));
			y = root + 1;
		}
		else if (input-rsquare < (diff/2+1)) {
			x = root + 1;
			y = input-rsquare;
		}
		else if (input - rsquare == diff/2+1) {
			x = root+1;
			y = root+1;
		}
		if (root%2 == 1) {
			std::swap(x,y);
		}

		printf("%d %d\n",x,y);
	}
	return 0;
}
