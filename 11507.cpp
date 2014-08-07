//11507 - Bender B. Rodríguez Problem

#include <iostream>
#include <string>
using namespace std;

string getNextDirection(string currDir, string nextCommand){
	if(currDir=="+x"){
		if(nextCommand=="No"){
			return currDir;
		}
		else if(nextCommand=="+y"){
			return "+y";
		}
		else if(nextCommand=="-y"){
			return "-y";
		}
		else if(nextCommand=="+z"){
			return "+z";
		}
		else if(nextCommand=="-z"){
			return "-z";
		}
	}
	else if(currDir=="-x"){
		if(nextCommand=="No"){
			return currDir;
		}
		else if(nextCommand=="+y"){
			return "-y";
		}
		else if(nextCommand=="-y"){
			return "+y";
		}
		else if(nextCommand=="+z"){
			return "-z";
		}
		else if(nextCommand=="-z"){
			return "+z";
		}
	}
	else if(currDir=="+y"){
		if(nextCommand=="No"){
			return currDir;
		}
		else if(nextCommand=="+y"){
			return "-x";
		}
		else if(nextCommand=="-y"){
			return "+x";
		}
		else if(nextCommand=="+z"){
			return "+y";
		}
		else if(nextCommand=="-z"){
			return "+y";
		}
	}
	else if(currDir=="-y"){
		if(nextCommand=="No"){
			return currDir;
		}
		else if(nextCommand=="+y"){
			return "+x";
		}
		else if(nextCommand=="-y"){
			return "-x";
		}
		else if(nextCommand=="+z"){
			return "-y";
		}
		else if(nextCommand=="-z"){
			return "-y";
		}
	}
	else if(currDir=="+z"){
		if(nextCommand=="No"){
			return currDir;
		}
		else if(nextCommand=="+y"){
			return "+z";
		}
		else if(nextCommand=="-y"){
			return "+z";
		}
		else if(nextCommand=="+z"){
			return "-x";
		}
		else if(nextCommand=="-z"){
			return "+x";
		}
	}
	else if(currDir=="-z"){
		if(nextCommand=="No"){
			return currDir;
		}
		else if(nextCommand=="+y"){
			return "-z";
		}
		else if(nextCommand=="-y"){
			return "-z";
		}
		else if(nextCommand=="+z"){
			return "+x";
		}
		else if(nextCommand=="-z"){
			return "-x";
		}
	}
	return "0";
	
}


int main(){
	string tempString;
	string currDir;
	int n=0;
	cin >> n;
	while(n>0){
		currDir = "+x";
		n--;
		while(n--){
			cin >> tempString;
			currDir=getNextDirection(currDir,tempString);
		}
		cout << currDir << endl;
		cin >> n;
	}
	return 0;
}
