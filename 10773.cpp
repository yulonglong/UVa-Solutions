//Steven Kester Yuwono - UVa 10773

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int tc;
    scanf("%d",&tc);
    for(int e=1;e<=tc;e++){
        double ans,ans1,ans2;
        int d,v,u;
        scanf("%d %d %d", &d,&v,&u);
        
        if((v==0)||(u==0)||(v>=u)){
            printf("Case %d: can't determine\n",e);
            continue;
        }
        
        ans1 = ((double)d)/((double)u);
        ans2 = ((double)d)/(sqrt((double)(u*u)-(v*v)));
        
        ans = fabs(ans2-ans1);
        
        printf("Case %d: %.3f\n",e,ans);
    }
    return 0;
}