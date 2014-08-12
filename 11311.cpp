//Steven Kester Yuwono - UVa 11311

#include <iostream>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int m,n,r,c;
        cin >> m >> n >> r >> c;
        if((int)((m-r-1)^(n-c-1)^r^c)!=0){
            cout << "Gretel" << endl;
        }
        else{
            cout << "Hansel" << endl;
        }
    }
}