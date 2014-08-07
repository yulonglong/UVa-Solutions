//11172 - Relational Operators

#include <iostream>
using namespace std;

char getOperator(int a,int b){
	if (a==b){
		return '=';
	}
	else if(a<b){
		return '<';
	}
	else if(b<a){
		return '>';
	}
	return '0';
}

int main(){
	int n=0;
	int a=0;
	int b=0;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> a >> b;
		cout << getOperator(a,b) << endl;
	}
	return 0;
}
