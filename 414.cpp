//Steven Kester Yuwono - UVa 414

#include <iostream>
#include <cstring>
#define MAXSIZE 100
#define MAX 25
using namespace std;

int countSpace[MAXSIZE];

int main(){
	int n;
	string temp;
	while ((cin >> n)&&(n>0)){
		getline(cin,temp); // dummy getline
		memset(countSpace,0,sizeof(countSpace));
		for(int i=0;i<n;i++){
			getline(cin,temp);
			for(int j=0;j<MAX;j++){
				if(temp[j]!='X'){
					countSpace[i]++;
				}
			}
		}

		int min = 2000000000;
		for(int i=0;i<n;i++){
			if(min>countSpace[i]){
				min = countSpace[i];
			}
		}

		int openSpace = 0;
		for(int i=0;i<n;i++){
			openSpace = openSpace + (countSpace[i] - min);
		}

		cout << openSpace << endl;
	}
	return 0;
}