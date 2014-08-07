#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int memo[110][2550];
int cal[110];
vector<int> result;

int dp(int n,int remaining){
    for(int step=1;step<=n;step++){
        for(int j=1;j<2550;j++){
            if(memo[step-1][j]==1){
                memo[step][j]=1;
                //cout << "step " << step << endl;
                //cout << remaining << endl;
                remaining=j;
                if(cal[step]==remaining){
                    //cout<<"A"<< endl;
                    result.clear();
                    return 0;
                }
                else if(cal[step]<remaining){
                    memo[step][remaining-cal[step]]=1;
                }
                else{
                    result.push_back(remaining-cal[step]);
                }
            }
        }
    }
    int minz=-2000000000;
    for(unsigned int i=0;i<result.size();i++){
        minz=max(minz,result[i]);
    }
    result.clear();
    return minz;
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        for(int i=0;i<110;i++){
            for(int j=0;j<2550;j++){
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
        int result=dp(n,expected);
        if(result==-2000000000){
            printf("NO SOLUTION\n");
        }
        else{
            result=expected-result;
            printf("%d\n",result);
        }
    }
    return 0;
}