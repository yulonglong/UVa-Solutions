//uva 10684
#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in2.txt","r",stdin);
	int n;
	cin >> n;
	while(n!=0){
		int rangeSum=0;
		int maxi=-1;
		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			rangeSum+=temp;
			maxi= max(maxi,rangeSum);
			if(rangeSum<0){
				rangeSum=0;
			}
		}
		if (maxi>0){
			cout << "The maximum winning streak is " << maxi << "." << endl;
		}
		else{
			cout << "Losing streak." << endl;
		}
		cin >> n;
	}
	return 0;
}
