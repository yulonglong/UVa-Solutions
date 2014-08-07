//uva 12397
// Roman Numerals

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <map>
#include <string>
using namespace std;

int getNumSticks(string input){
	int counter=0;
	for(int i=0;i<(int)input.length();i++){
		if(input[i]=='I'){
			counter+=1;
		}
		else if(input[i]=='V'){
			counter+=2;
		}
		else if(input[i]=='X'){
			counter+=2;
		}
		else if(input[i]=='L'){
			counter+=2;
		}
		else if(input[i]=='C'){
			counter+=2;
		}
		else if(input[i]=='D'){
			counter+=3;
		}
		else if(input[i]=='M'){
			counter+=4;
		}
	}
	return counter;
}

void AtoR(int A) {
  string ans;
  map<int, string> cvt;
  cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
  cvt[100]  = "C"; cvt[90]  = "XC"; cvt[50]  = "L"; cvt[40]  = "XL";
  cvt[10]   = "X"; cvt[9]   = "IX"; cvt[5]   = "V"; cvt[4]   = "IV";
  cvt[1]    = "I";
  // process from larger values to smaller values
  for (map<int, string>::reverse_iterator i = cvt.rbegin();
       i != cvt.rend(); i++)
    while (A >= i->first) {
		ans = ans + ((string)i->second).c_str();
      A -= i->first;
      }
      int result = getNumSticks(ans);
 cout <<result<< endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  char str[1000];

  while (gets(str) != NULL) {
    AtoR(atoi(str)); // Arabic to Roman Numerals
  }

  return 0;
}
