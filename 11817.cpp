//Steven Kester Yuwono - UVa 11817
#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
#define R 6371009 

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double getTunnelDistance(double x1,double x2, double y1, double y2, double z1, double z2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

double getArcDistance(double d){
	return R*2*asin(d/(2*R));
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int tc;
	cin >> tc;
	while(tc--){
		double latitude1, longitude1, latitude2, longitude2;
		cin >> latitude1 >> longitude1 >> latitude2 >> longitude2;
		
		longitude1 = DEG_to_RAD(longitude1);
		longitude2 = DEG_to_RAD(longitude2);
		latitude1 = DEG_to_RAD(latitude1);
		latitude2 = DEG_to_RAD(latitude2);
		
		double x1 = R*cos(latitude1)*cos(longitude1);
		double y1 = R*cos(latitude1)*sin(longitude1);
		double z1 = R*sin(latitude1);
		
		double x2 = R*cos(latitude2)*cos(longitude2);
		double y2 = R*cos(latitude2)*sin(longitude2);
		double z2 = R*sin(latitude2);
		
		double tunnelDist = getTunnelDistance(x1,x2,y1,y2,z1,z2);
		double arcDist = getArcDistance(tunnelDist);
		
		cout << fixed;
		cout << setprecision(0);
		cout << arcDist-tunnelDist << endl;		
	}
	return 0;
}
