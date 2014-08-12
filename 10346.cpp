//Steven Kester Yuwono - UVa 10346

#include <iostream>
using namespace std;

int main(){
    int n,k;
    while(cin >> n >> k){
        int ans=0;
        while((n>0)&&(n/k!=0)){
            int cigFromButt = n/k;
            int butt = cigFromButt*k;
            n=n-butt;
            ans=ans+butt;
            n=n+cigFromButt;
        }
        if(n/k==0){
            ans=ans+n;
        }
        cout << ans << endl;
    }
    return 0;
}