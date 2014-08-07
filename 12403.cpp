//Steven Kester Yuwono - UVa 12403 - Save Setu

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int tempInt=0;
	int amount=0;
	string command;
	int n=0;
	cin >> n;
	getline(cin,command);
	while(n--){
		getline(cin,command);
		if(command=="report"){
			cout << amount << endl;
		}
		else{
			command=command.substr(7);
			tempInt=atoi(command.c_str());
			amount+=tempInt;
		}
	}
	return 0;
}
