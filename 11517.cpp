//Steven Kester Yuwono - UVa 11517

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int x;
    int y;
}pari;

int memo[110][10050];
int cal[110];
vector<pari> result;

pari dp(int n,int remaining){
    for(int step=1;step<=n;step++){
        for(int j=1;j<10050;j++){
            if(memo[step-1][j]>0){
                memo[step][j]=memo[step-1][j];
                //cout << "step " << step << endl;
                //cout << remaining << endl;
                remaining=j;
                if(cal[step]<remaining){
                    memo[step][remaining-cal[step]]=memo[step-1][j]+1;
                }
                else{
                    int tempy=memo[step-1][j]+1;
                    int tempx=remaining-cal[step];
                    pari newpair;
                    newpair.x=tempx;
                    newpair.y=tempy;
                    result.push_back(newpair);
                }
            }
        }
    }
    int minx=-2000000000;
    int miny=2000000000;
    int x,y;
    for(unsigned int i=0;i<result.size();i++){
        x=result[i].x;
        y=result[i].y;
        if(minx<x){
            minx=x;
            miny=y;
        }
        else if(minx==x){
            if(miny>y){
                miny=y;
            }
        }
    }
    
    pari newpair;
    newpair.x=minx;
    newpair.y=miny;
    result.clear();
    return newpair;
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0;i<110;i++){
            for(int j=0;j<10050;j++){
                memo[i][j]=-1;
            }
        }
        int expected;
        scanf("%d",&expected);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&cal[i]);
        }
        memo[0][expected]=1;
        
        
        pari result=dp(n,expected);
        printf("%d %d\n",expected-result.x,result.y-1);
        
    }
    return 0;
}
