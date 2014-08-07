//Steven Kester Yuwono - UVa 10114

#include <iostream>
using namespace std;

int main(){
	int numMonths=0;
	double dp=0;
	double loan=0;
	double car=0;
	int numPercentage=0;
	float depreciation[110];
	int tempMonth;
	double installment=0;
	
	
	cin >> numMonths >> dp >> loan >> numPercentage;
	installment = loan / numMonths;
	while (numMonths>0){
		for (int i=0;i<110;i++){
			depreciation[i]=-1;
		}
		for(int i=0;i<numPercentage;i++){
			cin >> tempMonth;
			cin >> depreciation[tempMonth];
		}
		for(int i=0;i<110;i++){
			if (depreciation[i]<0){
				depreciation[i]=depreciation[i-1];
			}
			//cout << depreciation[i] << endl;
		}
		
		car = (dp+loan)*(1.0-depreciation[0]);
		loan = loan;
		
		if (loan<car){
			cout << "0 months" << endl;
		}
		else{
			for(int i=1;(i<=numMonths)&&(loan>=car);i++){
				car=car*(1.0-depreciation[i]);
				loan=loan-installment;
				//cout << car << endl;
				//cout << loan << endl;
				if(car>loan){
					if(i>1){
						cout << i << " months" << endl;
					}
					else{
						cout << "1 month" << endl;
					}
				}
			}
		}
		cin >> numMonths >> dp >> loan >> numPercentage;
		installment = loan / numMonths;
	}
			
		
	
	
	return 0;
}
