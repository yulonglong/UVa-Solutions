//Steven Kester Yuwono - UVa 12455

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		bool valid=false;
		int array[23];
		int n;
		scanf("%d",&n);
		int p;
		scanf("%d",&p);
		for(int i=0;i<p;i++){
			scanf("%d",&array[i]);
		}
		for(int i=0;i<(1<<p);i++){
			int sum=0;
			for(int j=0;j<p;j++){
				if(i&(1<<j)){
					sum+=array[j];
				}
				if(sum==n){
					valid=true;
					break;
				}
			}
		}
		if(valid){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
