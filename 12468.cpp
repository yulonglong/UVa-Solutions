//12468 Zapping

#include <iostream>
using namespace std;

int main(){
    int first;
    int second;
    int num1;
    int num2;
    cin >> first >> second;
    while(!((first==-1)&&(second==-1))){
        if(first<second){
            num1=second-first;
            num2=first+100-second;
        }
        else if(second<first){
            num1=first-second;
            num2=second+100-first;
        }
        else{
            num1=0;
            num2=0;
        }
        
        if(num1<num2){
            cout << num1 << endl;
        }
        else{
            cout << num2 << endl;
        }
        cin >> first >> second;
    }
    return 0;
}