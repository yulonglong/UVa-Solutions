//Steven Kester Yuwono - UVa 10664
//Top-down DP

#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int weight[25];
int memo[205][205];
int N;

void init(){
    memset(weight,0,sizeof(weight));
    memset(memo,-1,sizeof(memo));
}


int dp(int remaining, int state){
    if(state==N){
        return 0;
    }
    if(memo[remaining][state]!=-1){
        return memo[remaining][state];
    }
    int a=0;
    int b=0;
    if(remaining-weight[state]>=0){
        a=dp(remaining-weight[state],state+1)+weight[state];
    }
    b = dp(remaining,state+1);
    int ans = max(a,b);
    return memo[remaining][state] = ans;
}

int main(){
    int tc;
    cin >> tc;
    //cout << tc << endl;
    string line;
    getline(cin,line);
    while(tc--){
        init();
        getline(cin,line);
        //cout << line << endl;
        istringstream istream(line);
        int index=0;
        int totalWeight=0;
        while(istream>>weight[index]){
            totalWeight = totalWeight + weight[index];
            index++;
        }
        N=index;
        //cout << totalWeight << endl;
        if(totalWeight%2==1){
            cout << "NO" << endl;
        }
        else{
            int aim = totalWeight/2;
            int ans = dp(aim,0);
            
            if(ans==aim){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            
        }
    }
    return 0;
}
