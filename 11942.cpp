//Steven Kester Yuwono - UVa 11942

#include <iostream>
using namespace std;

int main(){
    bool asc=false;
    bool desc=false;
    int curr;
    int next;
    int n;
    cin >> n;
    cout <<"Lumberjacks:" << endl;
    
    while(n--){
        cin >> curr;
        for (int i=1;i<10;i++){
            cin >> next;
            if(next>curr){
                asc = true;
            }
            if(next<curr){
                desc = true;
            }
            curr=next;
        }
        
        if(asc&&desc){
            cout << "Unordered" << endl;
        }
        else{
            cout << "Ordered" << endl;
        }
        
        asc=false;
        desc=false;
    }
    
    return 0;
}
