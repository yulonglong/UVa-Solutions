//Steven Kester Yuwono - UVa 10730

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#define MAX 10010
using namespace std;

int store[MAX];
int storeIndex[MAX];

bool isAntiarithmetic(int n){
	int diffMax  = n/3;

	for (int d=1; d<=diffMax+1; d++){

		for (int i=0;i<n;i++){
			int currIndex = i;
			int count = 0;
			while(true){
				if(count >= 2){
					return false;
				}
				int nextIndex = storeIndex[store[currIndex] + d];
				if(nextIndex > currIndex){
					count++;
					currIndex = nextIndex;
				}
				else{
					break;
				}
			}
		}

	}
	return true;
}

int main(){
	string line;
	while ((getline(cin,line))&&(line!="0")){
		memset(store,0,sizeof(store));
		memset(storeIndex,0,sizeof(storeIndex));
		int n;
		string nStr;
		istringstream istream(line);
		getline(istream,nStr,':');
		n = atoi(nStr.c_str());
		for(int d=0; d<n; d++){
			istream >> store[d];
			storeIndex[store[d]] = d;
		}

		bool antiAtm = true;
		if(!isAntiarithmetic(n)){
			cout << "no" << endl;
		}
		else{
			cout << "yes" << endl;
		}


	}
	return 0;
}