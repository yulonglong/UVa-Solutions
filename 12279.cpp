//12279 - Emoogle Balance

#include <iostream>
using namespace std;

int main(){
	int counter=1;
	int temp;
	int num;
	int treat=0;
	int treated=0;
	cin >> num;
	while(num!=0){
		for(int i=0;i<num;i++){
			cin >> temp;
			if(temp==0){
				treated++;
			}
			else{
				treat++;
			}
		}
		
		cout << "Case " << counter << ": "; 
		cout << treat-treated << endl;
		
		counter++;
		treat=0;
		treated=0;
		cin >> num;
	}
	return 0;
}
