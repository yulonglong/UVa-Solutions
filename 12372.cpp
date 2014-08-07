//Steven Kester Yuwono - UVa 12372 - Packing for Holiday

#include <iostream>
using namespace std;

int main(){
	string good="good";
	int n=0;
	int temp=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int z=0;z<3;z++){
			cin >> temp;
			if(temp>20){
				good="bad";
			}
		}
		cout << "Case " << i << ": ";
		cout << good << endl;
		good="good";
	}
	return 0;
}
