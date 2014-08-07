//uva 12708
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		ull input;
		cin >> input;
		cout << (input>>1) << endl;
	}
	return 0;
}
