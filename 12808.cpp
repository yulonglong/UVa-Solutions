//Steven Kester Yuwono - UVa 12808

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--){
		double L, D, H ,V;
		cin >> L >> D >> H >> V;

		// using equation d = ut + 0.5at^2
		double timeTaken = sqrt( (2.0*H) / 9810.0);
		double distanceTravelled = V * timeTaken;

		double poolMin = D;
		double poolMax = D + L;

		if ((distanceTravelled < poolMin-500.0) || (distanceTravelled > poolMax + 500.0)){
			cout << "FLOOR" << endl;
		}
		else if ((distanceTravelled > poolMin+500.0) && (distanceTravelled < poolMax - 500.0)) {
			cout << "POOL" << endl;
		}
		else {
			cout << "EDGE"  << endl;
		}
	}
	return 0;
}