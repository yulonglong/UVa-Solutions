//Steven Kester Yuwono - UVa 11797

#include <iostream>
#include <queue>
using namespace std;

int getValue(string name){
    if(name=="Ja"){
        return 0;
    }
    else if(name=="Sam"){
        return 1;
    }
    else if(name=="Sha"){
        return 2;
    }
    else if(name=="Sid"){
        return 3;
    }
    else if(name=="Tan"){
        return 4;
    }
    return -1;
}


int main(){
    int tc;
    cin >> tc;
    for(int d=1;d<=tc;d++){
        int N,M, k;
        int duration[6];
        string curr;
        string temp;
        string name;
        queue<string> list[6];
        for(int i=0;i<5;i++){
            while(!list[i].empty()){
                list[i].pop();
            }
            duration[i]=0;
        }
        cin >> M >> N >> curr;
        
        for(int i=0;i<5;i++){
            cin >> k;
            while(k--){
                cin >> name;
                list[i].push(name);
            }
        }
        
        int time=0;
        
        if(time+M<N){
            duration[getValue(curr)]+=M;
            time=time+M;
        }
        else{
            int tempInt = N-time;
            if(tempInt>0){
                duration[getValue(curr)]+=tempInt;
            }
            time=N;
        }
        
        while(time<N){
            temp=curr;
            curr=list[getValue(curr)].front();
            list[getValue(temp)].pop();
            list[getValue(temp)].push(curr);
            if (time+2+M<N){
                duration[getValue(curr)]+=M;
                time=time+2+M;
            }
            else{
                int tempInt = N-time-2;
                if(tempInt>0){
                    duration[getValue(curr)]+=tempInt;
                }
                time=N;
            }
        }
        
        cout << "Case " << d << ":" << endl;
        cout << "Ja " << duration[0] << endl;
        cout << "Sam " << duration[1] << endl;
        cout << "Sha " << duration[2] << endl;
        cout << "Sid " << duration[3] << endl;
        cout << "Tan " << duration[4] << endl;
        
    }
    return 0;
}
