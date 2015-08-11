// Steven Kester Yuwono - UVa 406

#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 1010
using namespace std;

bool isPrime[MAX];

void initPrime(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<MAX;i++){
		if (isPrime[i]) {
			for(int j=i+i;j<MAX;j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
	initPrime();
	int n,c;
	while (scanf("%d %d",&n,&c)==2) {
		vector<int> ans;
		for(int i=1;i<=n;i++){
			if (isPrime[i]) ans.push_back(i);
		}
		int cPrint = 0;
		if (ans.size()%2 == 1) cPrint = c*2-1;
		else cPrint = c*2;

		printf("%d %d:",n,c);
		if (cPrint < ans.size()) {
			int diff = ans.size()-cPrint;
			for(int i=diff/2;i<cPrint+diff/2;i++){
				printf(" %d",ans[i]);
			}
		}
		else {
			for(int i=0;i<(int)ans.size();i++){
				printf(" %d",ans[i]);
			}
		}
		printf("\n\n");
	}
	return 0;
}
