#include <cstdio>
using namespace std;

int main(){
	char cmd[30];
	int n,north,prev,top,west;
    while(scanf("%d\n",&n) && n){    
        top = 1; 
        north = 2;
        west = 3;    
        for(int i=0;i!=n;i++){
            gets(cmd);
            prev=top;
            if(cmd[0]=='n'){
				top = 7-north;
				north = prev;
			}
            else if(cmd[0]=='s'){
                top = north;
                north = 7-prev;
			}
            else if(cmd[0]=='w'){
                top = 7-west;
                west = prev;
			}
            else{
			   top = west;
			   west = 7-prev;
			}
        }
        printf("%d\n",top);
    }
    return 0;
}
