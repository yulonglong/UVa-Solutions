//Steven Kester Yuwono - UVa 11242

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int frontNum, rearNum;
	while(scanf("%d %d",&frontNum,&rearNum)==2){
		vector<int> front, rear;
		for(int i = 0;i<frontNum;i++){
			int temp;
			scanf("%d",&temp);
			front.push_back(temp);
		}
		for(int i = 0;i<rearNum;i++){
			int temp;
			scanf("%d",&temp);
			rear.push_back(temp);
		}

		vector<double> driveRatio;
		for(int i=0;i<rearNum;i++){
			for(int j=0;j<frontNum;j++){
				double tempAns = (double)rear[i]/(double)front[j];
				driveRatio.push_back(tempAns);
			}
		}

		sort(driveRatio.begin(),driveRatio.end());

		double maxSpread = 0;
		for(int i=0;i<(int)driveRatio.size()-1;i++){
			double currSpread = driveRatio[i+1]/driveRatio[i];
			if(maxSpread<currSpread){
				maxSpread = currSpread;
			}
		}

		printf("%.2f\n", maxSpread);
	}

	return 0;
}