//Steven Kester Yuwono - UVa 11586

#include <iostream>
#include <sstream>
using namespace std;

int main(){
	int tc;
	cin >> tc;

	string line;
	getline(cin,line); //dummy getline
	while(tc--){
		getline(cin,line);
		istringstream istream(line);
		string currword;

		int counterM = 0;
		int counterF = 0;
		while(istream >> currword){
			if(currword[0]=='M'){
				counterM++;
			}
			else{
				counterF++;
			}
			if(currword[1]=='M'){
				counterM++;
			}
			else{
				counterF++;
			}
		}

		if ( (counterM!=counterF)||((counterM<=1)&&(counterF<=1)) ){
			cout << "NO LOOP" << endl;
		}
		else{
			cout << "LOOP" << endl;
			
		}

	}
	return 0;
}