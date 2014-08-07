#include <iostream>
using namespace std;

int main(){
    int nWall;
    int curr;
    int next;
    int high=0;
    int low=0;
    
    int n=0;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> nWall;
        cin >> curr;
        nWall--;
        while(nWall--){
            cin >> next;
            if(next>curr){
                high++;
            }
            if(next<curr){
                low++;
            }
            curr=next;
        }
        cout << "Case " << i << ": " << high << " " << low << endl;
        high=0;
        low=0;
        
    }
    return 0;
}