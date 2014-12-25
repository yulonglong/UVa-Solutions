//Steven Kester Yuwono - UVa 12502

#include <cstdio>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int a, b , money;
		scanf("%d %d %d",&a,&b,&money);
		int total = (a*60+b*60)/3;
		int extraA = a*60-total;
		int extraB = b*60-total;
		int extraPaid = extraA+extraB;
		int ans = money*extraA/extraPaid;
		if(ans < 0){
			ans = 0;
		}
		printf("%d\n",ans);
	}
	return 0;
}