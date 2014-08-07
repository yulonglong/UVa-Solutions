//Steven Kester Yuwono - UVa 11559 - Event Planning

#include <iostream>
using namespace std;

int main(){
	int N=0;
	int B=0;
	int H=0;
	int W=0;
	int tempAns=600000;
	int ans=600000;
	int hotelPrice=0;
	int numAvailable=0;
	bool enough=false;
	
	
	while (cin >> N >> B >> H >> W){
		ans=600000;
		for (int i=0;i<H;i++){
			enough=false;
			cin >> hotelPrice;
			for(int j=1;j<=W;j++){
				cin >> numAvailable;
				if (N<=numAvailable){
					enough=true;
				}
			}
			if(enough){
				tempAns=N*hotelPrice;
				if(tempAns<B){
					if(tempAns<ans){
						ans=tempAns;
					}
				}
			}
		}
		if (ans<=500000){
			cout << ans << endl;
		}
		else{
			cout << "stay home" << endl;
		}
	}

	
	return 0;
}
