//11498 - Division of Nlogonia

#include <iostream>
#include <string>
using namespace std;

	


int main(){
	int n=0;
	int divX = 0;
	int divY = 0;
	int x=0;
	int y=0;
	cin >> n;
	while(n!=0){
		cin >> divX >> divY;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			if ((x==divX)||(y==divY)){
				cout << "divisa" << endl;;
			}
			else if (x<divX){
				if (y<divY){
					cout << "SO" << endl;
				}
				else{
					cout << "NO" << endl;
				}
			}
			else{
				if(y>divY){
					cout << "NE" << endl;
				}
				else{
					cout << "SE" << endl;
				}
			}
		}
		cin >> n;
	}
	return 0;
}
