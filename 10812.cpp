//10812 - Beat the Spread!

#include <iostream>
using namespace std;

int main(){
	int s,d;
	int n;
	cin >> n;
	while(n--){
		cin >> s >> d;
		for(int i=0;i<1000;i++){
			int small=i;
			int big=i+d;
			if(small+big==s){
				cout << big << " " << small << endl;
				break;
			}
			else if (small+big>s){
				cout << "impossible" << endl;
				break;
			}
		}
	}
	return 0;
}
