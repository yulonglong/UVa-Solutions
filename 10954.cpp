//Steven Kester Yuwono - UVa 10954

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

class comparison{
public:
    bool operator()(int a, int b){
        if(a>b){
            return true;
        }
        return false;
    }
};

int main(){
    priority_queue<int,vector<int>,comparison> pq;
    int n;
    int temp;
    long long total=0;
    long long temptotal=0;
    scanf("%d",&n);
    while(n){
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            pq.push(temp);
        }
        while(pq.size()>1){
            temptotal = pq.top();
            pq.pop();
            temptotal = temptotal + pq.top();
            pq.pop();
            
            total=total+temptotal;
            pq.push(temptotal);
        }
        pq.pop();
        cout << total << endl;
        
        total=0;
        temptotal=0;
        scanf("%d",&n);
    }
    
    return 0;
}
