#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int x[3];
	scanf("%d %d %d\n",&x[0],&x[1],&x[2]);
	while(x[0]!=0){
		if((x[0]!=x[1])&&(x[1]!=x[2])&&(x[0]!=x[2])){
			printf("%d %d %d\n",1,1,2);
		}
		else if((x[0]==13)&&(x[1]==13)&&(x[2]==13)){
			printf("*\n");
		}
		else if((x[0]==x[1])&&(x[1]==x[2])&&(x[0]==x[2])){
			printf("%d %d %d\n",x[0]+1,x[0]+1,x[0]+1);
		}
		else{
			
			sort(x,x+3);
			if(x[0]==x[1]){
				swap(x[0],x[2]);
			}
			if((x[0]==12)&&(x[1]==13)){
				x[0]=1;
				x[1]=1;
				x[2]=1;
			}
			else if(x[0]+1!=x[1]){
				if(x[0]+1<=13){
					x[0]++;
				}
				else{
					x[0]=1;
					x[1]++;
					x[2]++;
				}
			}
			else{
				if(x[0]+2<=13){
					x[0]+=2;
				}
				else{
					x[0]=1;
					x[1]++;
					x[2]++;	
				}
			}
			sort(x,x+3);
			printf("%d %d %d\n",x[0],x[1],x[2]);
			
		}
		
		scanf("%d %d %d\n",&x[0],&x[1],&x[2]);
	}
	return 0;
}
