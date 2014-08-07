//uva 484
#include <bits/stdc++.h>
#define max 1000002
#define max2 2000004
using namespace std;

int store[max2];
int freq[max2];

int main(){
	memset(store,0,sizeof(store));
	memset(freq,0,sizeof(freq));
	int tempInt;
	int counter=0;
	
	while(cin>>tempInt){
		store[counter++] = tempInt+max;
		freq[tempInt+max]++;
	}

	for(int i=0;i<counter;i++){
		int temp = store[i];
		if(freq[temp]!=0){
			cout << temp-max << " " << freq[temp] << endl;
			freq[temp]=0;
		}
	}
	return 0;
}
