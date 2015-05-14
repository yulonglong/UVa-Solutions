// Steven Kester Yuwono - UVa 640

#include <cstdio>
using namespace std;

bool self[1500001];

int main(){
	for(int i=1;i<=1000000;i++){
		int total = i;
		int temp = i;
		while(temp > 0){
			total += temp%10;
			temp /= 10;
		}
		self[total] = true;
	}

	for(int i=1;i<=1000000;i++){
		if(self[i] == false){
			printf("%d\n",i);
		}
	}
	return 0;
}