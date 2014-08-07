//Steven Kester Yuwono - UVa 637 - Booklet Printing

#include <iostream>
using namespace std;

int main(){
	int counter=1;
	int n=0;
	cin >> n;
	while(n!=0){
		
		cout << "Printing order for " << n << " pages:" << endl;
		if(n==1){
			cout << "Sheet 1, front: Blank, 1" << endl;
		}
		else{
			if((n%4)==0){
				for(int i=1;i<=n/4;i++){
					cout << "Sheet " << i;
					cout << ", front: ";
					cout << n+1-counter;
					cout << ", ";
					cout << counter++;
					cout << endl;
					cout << "Sheet " << i;
					cout << ", back : ";
					cout << counter;
					cout << ", ";
					cout << n+1-counter++;
					cout << endl;
				}
			}
			else if((n%4)==3){
				cout << "Sheet " << "1";
				cout << ", front: ";
				cout << "Blank";
				cout << ", ";
				cout << counter++;
				cout << endl;
				cout << "Sheet " << "1";
				cout << ", back : ";
				cout << counter;
				cout << ", ";
				cout << n+2-counter++;
				cout << endl;
				for(int i=2;i<=(n/4)+1;i++){
					cout << "Sheet " << i;
					cout << ", front: ";
					cout << n+2-counter;
					cout << ", ";
					cout << counter++;
					cout << endl;
					cout << "Sheet " << i;
					cout << ", back : ";
					cout << counter;
					cout << ", ";
					cout << n+2-counter++;
					cout << endl;
				}
			}
			else if((n%4)==2){
				cout << "Sheet " << "1";
				cout << ", front: ";
				cout << "Blank";
				cout << ", ";
				cout << counter++;
				cout << endl;
				cout << "Sheet " << "1";
				cout << ", back : ";
				cout << counter;
				cout << ", ";
				cout << "Blank";
				cout << endl;
				counter++;
				for(int i=2;i<=(n/4)+1;i++){
					cout << "Sheet " << i;
					cout << ", front: ";
					cout << n+3-counter;
					cout << ", ";
					cout << counter++;
					cout << endl;
					cout << "Sheet " << i;
					cout << ", back : ";
					cout << counter;
					cout << ", ";
					cout << n+3-counter++;
					cout << endl;
				}
			}
			else if((n%4)==1){
				cout << "Sheet " << "1";
				cout << ", front: ";
				cout << "Blank";
				cout << ", ";
				cout << counter++;
				cout << endl;
				cout << "Sheet " << "1";
				cout << ", back : ";
				cout << counter++;
				cout << ", ";
				cout << "Blank";
				cout << endl;
				
				cout << "Sheet " << "2";
				cout << ", front: ";
				cout << "Blank";
				cout << ", ";
				cout << counter++;
				cout << endl;
				cout << "Sheet " << "2";
				cout << ", back : ";
				cout << counter;
				cout << ", ";
				cout << n+4-counter++;
				cout << endl;
				for(int i=3;i<=(n/4)+1;i++){
					cout << "Sheet " << i;
					cout << ", front: ";
					cout << n+4-counter;
					cout << ", ";
					cout << counter++;
					cout << endl;
					cout << "Sheet " << i;
					cout << ", back : ";
					cout << counter;
					cout << ", ";
					cout << n+4-counter++;
					cout << endl;
				}
			}
		}
		counter=1;
		cin >> n;
	}
	return 0;
}
