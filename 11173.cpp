//Steven Kester Yuwono - UVa 11173
//Bit Manipulation - XOR

#include <cstdio>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n, k;
		scanf("%d %d",&n,&k);
		printf("%d\n",(k^(k/2)) );
	}
	return 0;
}