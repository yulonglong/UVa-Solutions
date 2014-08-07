#include <iostream>
#include <cstdlib>
using namespace std;


void updateIns(string instruction[], int size){
    int tempInt;
    string temp;
    
    for(int i=1;i<=size;i++){
        if(instruction[i].length()>6){
            temp=instruction[i].substr(8);
            tempInt=atoi(temp.c_str());
            instruction[i]=instruction[tempInt];
        }
    }
}

int getAns(string instruction[], int size){
    int curr=0;
    for(int i=1;i<=size;i++){
        if(instruction[i]=="RIGHT"){
            curr++;
        }
        else{
            curr--;
        }
    }
    return curr;
}

int main(){
    string instruction[110];
    string temp;
    int n2;
    int n;
    cin >> n;
    getline(cin,temp);
    while(n--){
        cin >> n2;
        getline(cin,temp);
        for (int i=1;i<=n2;i++){
            getline(cin,instruction[i]);
        }
        updateIns(instruction,n2);
        cout << getAns(instruction,n2) << endl;
    }
    
    return 0;
}