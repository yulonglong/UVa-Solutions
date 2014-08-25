//Steven Kester Yuwono - UVa 11003
//Top Down DP

#include <iostream>
#include <cstring>
using namespace std;

int N;
int weight[1005];
int maxLoad[1005];
int memo[6005][1005];

void init(){
    memset(weight,0,sizeof(weight));
    memset(maxLoad,0,sizeof(maxLoad));
    memset(memo,-1,sizeof(memo));
}

int dp(int load,int state){
    //last state
    if (state==N){
        return 0;
    }
    //if have been computed
    if(memo[load][state]!=-1){
        return memo[load][state];
    }
    //standard dp
    int a=0;
    int b=0;
    if (load-weight[state]>=0){
        int currLoad = min((load-weight[state]),maxLoad[state]);
        a=dp(currLoad,state+1)+1;
    }
    b=dp(load,state+1);
    int ans = max(a,b);
    return memo[load][state]=ans;
}


int main(){
    cin >> N;
    while(N!=0){
        init();
        for(int i=0;i<N;i++){
            cin >> weight[i] >> maxLoad[i];
        }
        cout << dp(6004,0) << endl;
        cin >> N;
    }
    return 0;
}