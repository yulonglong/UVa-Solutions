//11332 - Summing Digits

#include <iostream>
using namespace std;

int getAns(int digit){
	int total=0;
	if(digit<10){
		return digit;
	}
	while(digit>=10){
		while(digit>0){
			total+=digit%10;
			digit=digit/10;
		}
		digit=total;
		total=0;
	}
	return digit;
}

int main(){
	int digit;
	cin >> digit;
	while(digit!=0){
		cout << getAns(digit) << endl;
		
		cin >> digit;
	}
	return 0;
}
