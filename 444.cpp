// Steven Kester Yuwono - UVa 444

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
	string word;
	while (getline(cin,word)){
		int length = word.length();
		reverse(word.begin(),word.end());

		if(isdigit(word[0])){
			int ascii = 0;
			for(int i=0;i<length;i++){
				ascii = ascii*10 + word[i]-48;
				if ((ascii >= 65 && ascii <= 90) ||
					(ascii >= 97 && ascii <= 122) ||
					ascii == 32 || ascii == 33 ||
					ascii == 44 || ascii == 46 ||
					ascii == 58 || ascii == 59 ||
					ascii == 63)
				{
					cout << (char) ascii;
					ascii = 0;
				}
			}
		}
		else {
			for(int i=0;i<length;i++){
				int temp = word[i];
				while(temp>0){
					cout << temp%10;
					temp /= 10;
				}
			}
		}
		cout << endl;
	}
	return 0;
}