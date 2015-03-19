// Steven Kester Yuwono - UVa 11038

#include <cstdio>
using namespace std;

long long countZero(long long input)
{
	if(input == -1) {
		return input;
	}
	long long originalInput = input;
	long long curr = input, sum = 0;
	int offset = 1;
	int modulo;
	while (curr >= 10) {
		modulo = curr%10;
		curr /= 10;
		if (modulo == 0)
			sum += ((curr-1)*offset) + (1 + originalInput%offset);
		else
			sum += (curr*offset);
		offset *= 10;
	}
	return sum;
}

int main()
{
	long long n,m;
	while ((scanf("%lld %lld",&n,&m)==2) && (n>=0) && (m>=0)) {
		printf("%lld\n",countZero(m) - countZero(n-1));
	}
	return 0;
}