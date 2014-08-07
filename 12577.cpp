//12577 - Hajj-e-Akbar

#include <iostream>
using namespace std;

int main(){
	int counter=1;
	string word;
	getline(cin,word);
	while(word!="*"){
		cout << "Case " << counter << ": ";
		if(word=="Hajj"){
			cout << "Hajj-e-Akbar" << endl;
		}
		else{
			cout << "Hajj-e-Asghar" << endl;
		}
		
		counter++;
		getline(cin,word);
	}
	return 0;
}
