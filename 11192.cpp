//Steven Kester Yuwono - UVa 11192
#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	int n;
	string word;
	cin >> n;
	while(n!=0){
		cin >> word;
		//cout << word << endl;
		string result;
		stack<char> st;
		unsigned int length=word.length();
		int x=length/n;
		for(int i=1;i<=n;i++){
			int a = (i*x);
			for(int j=a-1;j>=a-x;j--){
				cout << word[j];
			}
		}
		
		cout << result << endl;
		cin >> n;
	}
	return 0;
}
