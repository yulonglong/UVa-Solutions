//Steven Kester Yuwono - UVa 11723

#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int counter=0;
    int n,r;
    scanf("%d %d",&r,&n);
    while(!((n==0)&&(r==0))){
        int ans=0;
        counter++;
        if(r/n==0)
        {
            printf("Case %d: 0\n",counter);
            scanf("%d %d",&r,&n);
            continue;
        }
        
        ans=ceil(double(r)/n)-1;
        if(ans>26){
            printf("Case %d: impossible\n",counter);
        }
        else{
            printf("Case %d: %d\n",counter,ans);
        }
        scanf("%d %d",&r,&n);

    }
    return 0;
}