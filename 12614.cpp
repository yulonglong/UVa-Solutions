//Steven Kester Yuwono - UVa 12614 - Earn For Future

#include <cstdio>
using namespace std;

int main(){
    int num=0;
    int max=-1;
    int n;
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        scanf("%d",&n);
        while(n--){
            scanf("%d",&num);
            if(max<num){
                max=num;
            }
        }
        
        printf("Case %d: %d\n",i,max);
        max=-1;
        
    }
    return 0;
}