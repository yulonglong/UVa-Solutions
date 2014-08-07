//Steven Kester Yuwono - UVa 12643

#include <iostream>
using namespace std;

int main(){
    int N;
    int X;
    int Y;
    int ans;
    while(cin >> N){
        cin >> X >> Y;
        for(int i=1;i<=N;i++){
            X=(X+1)/2;
            Y=(Y+1)/2;
            ans=i;
            if(X==Y){
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}