//10646 - What is the Card?

#include <iostream>
#include <string>
using namespace std;


int main(){
	string temp;
	string ans;
	int n=0;
	cin >> n;
	for(int j=1;j<=n;j++){
		for(int i=0;i<52;i++){
			cin >> temp;
			if(i==32){
				ans=temp;
			}
		}
		
		cout << "Case " << j << ": ";
		cout << ans << endl;
	}
	return 0;
}
