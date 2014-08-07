//Steven Kester Yuwono - UVa 11547 - Automatic Answer

#include <iostream>
using namespace std;

int main(){
	int num=0;
	int n=0;
	cin >> n;
	while(n--){
		cin >> num;
		num=num*567;
		num=num/9;
		num=num+7492;
		num=num*235;
		num=num/47;
		num=num-498;
		num=num/10;
		if(num<0){
			num=num*(-1);
		}
		cout << num%10 << endl;
	}
	return 0;
}

