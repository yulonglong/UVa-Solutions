//Steven Kester Yuwono - UVa 11044 - Searching for Nessy

#include <iostream>
using namespace std;

int main(){
	int N=0;
	cin >> N;
	int n=0;
	int m=0;
	int totalX=0;
	int totalY=0;
	int total=0;
	while(N--){
		cin >> n >> m;
		n=n-2;
		m=m-2;
		totalX=n/3;
		if(n%3>0){
			totalX++;
		}
		totalY=m/3;
		if(m%3>0){
			totalY++;
		}
		total=totalX*totalY;
		cout << total << endl;
	}
	
	return 0;
}
