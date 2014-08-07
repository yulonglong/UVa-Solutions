//11364 - Parking

#include <iostream>
using namespace std;

int main(){
	int loc=0;
	int shop=0;
	int min=0;
	int max =0;
	int n=0;
	cin >> n;
	while(n--){
		min=100;
		max=-1;
		cin >> shop;
		for(int i=0;i<shop;i++){
			cin >> loc;
			if(min>loc){
				min=loc;
			}
			if(max<loc){
				max=loc;
			}
		}
		cout << (max-min)*2 << endl;
	}
	return 0;
}
