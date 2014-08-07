#include <cstdio>
using namespace std;

int main(){
	unsigned long x,y, ans;
	while(scanf("%ld %ld",&x,&y)==2){
		if(y>x){
			ans=y-x;
		}
		else{
			ans =x-y;
		}
		printf("%ld\n",ans);
	}
	return 0;
}
