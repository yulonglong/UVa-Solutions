//11799 horror dash

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string tempString;
	int tempInt=0;
	int ans=0;
	int N=0;
	cin >> N;
	getline(cin,tempString);
	for (int i=1;i<=N;i++){
		ans=0;
		getline(cin,tempString);
		istringstream instream(tempString);
		while(instream >> tempInt){
			if(ans<tempInt){
				ans=tempInt;
			}
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}
