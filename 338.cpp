//Steven Kester Yuwono - UVa 338

#include <iostream>
#define MAX 8;
using namespace std;

string code[8];

bool check(int size){
	for (int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			size_t found = code[i].find(code[j]);
			if ((found!=string::npos)&&(found==0)) {
				return false;
			}
			found = code[j].find(code[i]);
			if ((found!=string::npos)&&(found==0)) {
				return false;
			}
		}
	}
	return true;
}

int main(){
	string line;

	int tc = 1;
	int size = 0;
	while(cin >> line){
		if(line != "9"){
			code[size++] = line;
		}
		else{
			bool valid = check(size);
			if (valid){
				cout << "Set "<< tc << " is immediately decodable" << endl;
			}
			else{
				cout << "Set "<< tc << " is not immediately decodable" << endl;
			}
			tc++;
			size = 0;
		}
	}
	return 0;
}