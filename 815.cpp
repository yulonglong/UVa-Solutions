// Steven Kester Yuwono - UVa 815

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int tc = 1; 
	while (scanf("%d %d",&n,&m)==2 && (n||m)) {
		vector<double> house;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				double temp; scanf("%lf",&temp);
				house.push_back(temp);
			}
		}
		sort(house.begin(),house.end());
		double waterVolume; scanf("%lf",&waterVolume);
		int downCount = 1;
		int houseSize = house.size();
		double currHeight = house[0];
		double defaultVolume = house[0]*100*houseSize;
		double currVolume = 0;
		double extraHeight = 0;
		for(int i=1;i<houseSize;i++){
			double originalVolume = currVolume;
			currVolume += (house[i]-currHeight) * 100 * downCount;
			if (currVolume <= waterVolume) {
				downCount++;
				currHeight = house[i];
			}
			else {
				double diffVolume = waterVolume - originalVolume;
				extraHeight = diffVolume/100.0/downCount;
				break;
			}
		}
		if (currVolume <= waterVolume) {
			double diffVolume = waterVolume - currVolume;
			extraHeight = diffVolume/100.0/downCount;
		}
		printf("Region %d\n",tc++);
		printf("Water level is %.2f meters.\n",currHeight+extraHeight);
		printf("%.2f percent of the region is under water.\n\n",(double)downCount/(double)houseSize*100.0);
	}
}
