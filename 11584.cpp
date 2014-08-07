//Steven Kester Yuwono - UVa 11584

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int s[1010];
int intWord[1010];

bool isPalindrome(int start,int end){
	int size= end-start+1;
	for(int i=start;i<start+(size/2);i++){
		if(intWord[i]!=intWord[end+start-i]){
			return false;
		}
	}
	//cout <<"true" << endl;
	return true;
}

int main(){
	int tc;
	cin>> tc;
	while(tc--){
		memset(intWord,0,sizeof(intWord));
		string word;
		cin >> word;
		int size=word.length();
		for(int i=0;i<size;i++){
			intWord[i]=(int)word[i];
			//cout << intWord[i] << " ";
		}
        for (int i=0;i<1010;i++){
			s[i]=2000000000;
		}
 
        s[0]=0;
        s[1]=1;
        for(int i=1;i<size;i++){
            for(int j=0;j<=i;j++){
                if(isPalindrome(j,i)){
                    s[i+1]=min(s[i+1],s[j]+1);
                }
            }
        }
        printf("%d\n",s[size]);
	}
	return 0;
}
