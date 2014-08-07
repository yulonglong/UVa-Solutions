//11727 - Cost Cutting

#include <iostream>
using namespace std;

int main(){
	int n=0;
	int a=0;
	int b=0;
	int c=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b >> c;
		cout << "Case " << i << ": ";
		if(a<b){
			if(c<a){//cab
				cout << a << endl;
			}
			else if (b<c){//abc
				cout << b << endl;
			}
			else{//acb
				cout << c << endl;
			}
		}
		else{
			if(a<c){//bac
				cout << a << endl;
			}
			else if(c<b){//cba
				cout << b << endl;
			}
			else{//bca
				cout << c << endl;
			}
		}
	}
	return 0;
}
