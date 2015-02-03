//Steven Kester Yuwono - UVa 12720

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MODNUM 1000000007
using namespace std;
char buffer[100020];

int main(){
	int tc;
	scanf("%d",&tc);
	
	for(int d=1;d<=tc;d++){
		scanf("%s",buffer);
		int length = strlen(buffer);

		unsigned long long sum = 0;
		int leftPtr = (length-1)/2;
		int rightPtr = length/2;
		if(length%2 == 1) {
			sum = buffer[rightPtr]-'0';
			leftPtr--;
			rightPtr++;
		}
	
		while( leftPtr >= 0 && rightPtr < length){
			if ( buffer[leftPtr] > buffer[rightPtr]){
				sum = (sum * 2 + buffer[leftPtr]-'0') % MODNUM;
				sum = (sum * 2 + buffer[rightPtr] -'0') % MODNUM;
			}
			else{
				sum = (sum * 2 + buffer[rightPtr] -'0') % MODNUM;
				sum = (sum * 2 + buffer[leftPtr]-'0') % MODNUM;
			}
			leftPtr--;
			rightPtr++;
		}
		printf("Case #%d: %llu\n", d, sum);
	}
}