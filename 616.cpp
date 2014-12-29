//Steven Kester Yuwono - UVa 616

#include <cstdio>
#define MAX 5
using namespace std;

bool valid(int person, int coconut){
	int rem;
	int quo;
	for(int i=0;i<person;i++){
		coconut = coconut - 1;
		quo = coconut/person;
		rem = coconut%person;
		if(rem!=0){
			return false;
		}
		coconut = coconut - quo;
	}
	rem = coconut%person;
	if(rem!=0){
		return false;
	}
	return true;
}

int main(){
	int n;
	while(((scanf("%d",&n))==1)&&(n!=-1)){
		int index = -1;
		for(int i=MAX;i>=2;i--){
			if(valid(i,n)){
				index = i;
				break;
			}
		}
		if(index==-1){
			printf("%d coconuts, no solution\n",n);
		}
		else{
			printf("%d coconuts, %d people and 1 monkey\n",n,index);
		}	
	}
	return 0;
}