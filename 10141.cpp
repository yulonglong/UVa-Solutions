//Steven Kester Yuwono - UVa 10141 request for proposal

#include <iostream>
using namespace std;

int main(){
	int n;
	int p;
	double compliance=(-5);
	double price=1000000000;
	double tempPrice;
	int tempInt=0;
	double tempCompliance;
	string name;
	string tempName;
	string tempString;
	int counter=1;
	cin >> n >> p;
	
	while(!((n==0)&&(p==0))){
		getline(cin,tempString);
		for(int i=0;i<n;i++){
			getline(cin,tempString);
		}
		compliance = (-5);
		price=1000000000;
		for(int j=0;j<p;j++){
			getline(cin,tempName);
			cin >> tempPrice;
			cin >> tempInt;
			getline(cin,tempString);
			for(int i=0;i<tempInt;i++){
				getline(cin,tempString);
			}
			if(n!=0){
				tempCompliance = (double)tempInt/(double)n;
			}
			if(compliance<tempCompliance){
				compliance=tempCompliance;
				price = tempPrice;
				name=tempName;
			}
			else if(compliance==tempCompliance){
				if(tempPrice<price){
					compliance=tempCompliance;
					price = tempPrice;
					name=tempName;
				}
			}
		}
		if(counter>1){
			cout<<endl;
		}
		
		cout << "RFP #" << counter++ << endl;
		cout << name << endl;
		
		cin >> n >> p;
	}
	
	return 0;
}
