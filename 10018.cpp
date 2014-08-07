//uva  10018
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(long long num){
	char buffer[50];
	sprintf(buffer,"%lld",num);
	string word = buffer;
	int size = word.length()-1;
	for(int i=0;i<=size;i++){
		if(word[i]!=word[size-i]){
			return false;
		}
		if(i>size-i){
			break;
		}
	}
	return true;
}

long long reverseNum(long long num){
	long long result=0;
	while(num>0){
		result*=10;
		result+=num%10;
		num = num/10;
	}
	return result;
}

void process(long long num){
	int counter = 0;
	while(!isPalindrome(num)){
		long long reverse = reverseNum(num);
		num = num+reverse;
		counter++;
	}
	
	cout << counter << " " << num << endl;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long num;
		cin >> num;
		process(num);
	}
	return 0;
}
