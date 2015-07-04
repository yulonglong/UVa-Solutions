// Steven Kester Yuwono - UVa 11827

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int gcd (int a, int b) {
	int c;
	while (a>0) {
		c = a;
		a = b%a; 
		b = c;
	}
	return b;
}

int main() {
	int tc; cin >> tc;
	string line; getline(cin,line);
	while(tc--){
		getline(cin,line);
		istringstream istream(line);
		
		vector<int> num;
		int temp;
		while (istream >> temp) {
			num.push_back(temp);
		}

		int maxGCD = 1;
		for(int i=0;i<(int)num.size();i++){
			for(int j=i+1;j<(int)num.size();j++){
				maxGCD = max(maxGCD,gcd(num[i],num[j]));
			}
		}
		cout << maxGCD << endl;
	}
	return 0;
}
