// Steven Kester Yuwono - UVa 737

#include <cstdio>
#include <iostream>
using namespace std;

int minX, maxX, minY, maxY, minZ, maxZ;

int main() {
	int n;
	while ((scanf("%d",&n)==1) && (n>0)) {
		minX = minY = minZ = -2000000000;
		maxX = maxY = maxZ = 2000000000;
		for(int i=0;i<n;i++) {
			int x,y,z,len; scanf("%d %d %d %d",&x,&y,&z,&len);
			minX = max(minX,x);
			maxX = min(maxX,x+len);
			minY = max(minY,y);
			maxY = min(maxY,y+len);
			minZ = max(minZ,z);
			maxZ = min(maxZ,z+len);
		}
		int volume = (maxX-minX)*(maxY-minY)*(maxZ-minZ);
		if (volume < 0) volume = 0;
		printf("%d\n", volume);
	}
	return 0;
}
