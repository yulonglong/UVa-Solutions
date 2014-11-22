//Steven Kester Yuwono - UVa 11965

#include <iostream>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	for(int d=1;d<=tc;d++){
		if(d>1){
			cout << endl;
		}
		cout << "Case " << d << ":" << endl;
		int numLines;
		cin >> numLines;
		string line;
		getline(cin,line); //dummy getline to clear
		for(int i=0;i<numLines;i++){
			getline(cin,line);
			cout << line[0];
			for(int j=1;j<(int)line.length();j++){
				if(!((line[j]==' ')&&(line[j-1]==' '))){
					cout << line[j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}