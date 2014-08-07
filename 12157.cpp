//Steven Kester Yuwono - UVa 12157

#include <iostream>
using namespace std;


int getMile(int duration){
    int total=0;
    if(duration%30>=0){
        total++;
    }
    total += duration/30;
    total = total*10;
    return total;
}

int getJuice(int duration){
    int total=0;
    if(duration%60>=0){
        total++;
    }
    total += duration/60;
    total = total*15;
    return total;
}

int main(){
    int numCalls;
    int duration;
    int mile;
    int juice;
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> numCalls;
        while(numCalls--){
            cin >> duration;
            mile = mile + getMile(duration);
            juice = juice + getJuice(duration);
        }
        
        cout << "Case " << i << ": ";
        if (mile<juice) {
            cout << "Mile " << mile << endl;
        }
        else if(juice<mile){
            cout << "Juice " << juice << endl;
        }
        else{
            cout << "Mile Juice " << mile << endl;
        }
        
        mile =0;
        juice=0;
    }
    return 0;
}