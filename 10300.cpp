//10300 - Ecological Premium

#include <iostream>
using namespace std;

int main(){
	int numAnimals;
	int size;
	int eco;
	double ans=0;
	double totalAns=0;
	
	int n;
	cin >> n;
	int nFarm;
	while(n--){
		totalAns=0;
		cin >> nFarm;
		while(nFarm--){
			ans=0;
			cin >> size >> numAnimals >> eco;
			ans = (((double)size/numAnimals)*eco)*numAnimals;
			totalAns += ans;
		}
		cout << totalAns << endl;
	}
	return 0;
}
