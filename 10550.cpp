//10550 - Combination Lock

#include <iostream>
using namespace std;

int main(){
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int ans=720;
	int first=0;
	int second=0;
	int third=0;
	
	
	cin >> a >> b >> c >> d;
	
	while(!((a==0)&&(b==0)&&(c==0)&&(d==0))){
		ans=720;
		first=a-b;
		if (first<0){
			first=first+40;
		}
		first=first*9;
		ans=ans+first+360;
		
		second=c-b;
		if (second<0){
			second=second+40;
		}
		second=second*9;
		ans=ans+second;
		
		third=c-d;
		if (third<0){
			third=third+40;
		}
		third=third*9;
		ans=ans+third;
		
		cout << ans << endl;
		
		cin >> a >> b >> c >> d;
	}
		
	return 0;
}
