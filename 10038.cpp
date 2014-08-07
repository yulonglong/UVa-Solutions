//Steven Kester Yuwono - UVa 10038 - Jolly Jumpers

#include <cstdio>
using namespace std;

int main(){
	int num[3001];
	bool jolly[3001];
	int n;
	int temp;
	bool jollybool=true;
	while(scanf("%d",&n)==1){
		scanf("%d",&num[n]);
		for(int i=n-1;i>=1;i--){
			scanf("%d",&num[i]);
			temp=num[i+1]-num[i];
			if(temp<0){
				temp=temp*(-1);
			}
			jolly[temp]=true;
		}
		for(int i=1;i<n;i++){
			if(jolly[i]==false){
				jollybool=false;
				break;
			}
		}
		if(jollybool){
			printf("Jolly\n");
		}
		else{
			printf("Not jolly\n");
		}
		for(int i=0;i<n;i++){
			jolly[i]=false;
		}
		jollybool=true;
	}	
	
	return 0;
}
