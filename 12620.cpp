//Steven Kester Yuwono - UVa 12620
#include <bits/stdc++.h>
using namespace std;

int fib[310];
int sum[310];
	
void build(){
	fib[1]=1;
	fib[2]=1;
	for(int i=3;i<310;i++){
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>=100){
			fib[i]=fib[i]%100;
		}
	}
}
void build2(){
	memset(sum,0,sizeof(sum));
	sum[1]=1;
	sum[2]=2;
	for(int i=3;i<301;i++){
		sum[i]=sum[i-1]+fib[i];
	}
	return;
}

long long getSum(long long input){
	long long remainder = input%300;
	long long divisor = input/300;
	long long answer = divisor*sum[300];
	answer=answer+sum[remainder];
	return answer;
}

int main(){
	build();
	build2();
	int tc;
	cin >> tc;
	while(tc--){
		long long low,high;
		cin >> low >> high;
		cout << getSum(high)-getSum(low-1) << endl;
	}
	return 0;
}
