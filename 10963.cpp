//Steven Kester Yuwono - UVa 10963 - The Swallowing Ground

#include <iostream>
using namespace std;

int main(){
	int x,y;
	int nGrid;
	bool can;
	int diff=0;
	int newDiff=0;
	
	int n;
	cin >> n;
	while(n--){
		cin >> nGrid;
		nGrid--;
		cin >> x >> y;
		diff = x-y;
		while(nGrid--){
			cin >> x >> y;
			newDiff= x - y;
			if(newDiff!=diff){
				can = false;
			}
		}
		if(can){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
		if(n){
			cout << endl;
		}
		can=true;
	}
	return 0;
}
