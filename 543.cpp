//Steven Kester Yuwono - UVa 543

#include <iostream>
using namespace std;

bool isPrime(int num){
    if(num%2==0){
        return false;
    }
    
    for(int i=3;i<num/2;i=i+2){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    bool inside=false;
    int n;
    cin >> n;
    while(n){
        for(int i=3;i<=n/2;i=i+2){
            if ((isPrime(i))&&(isPrime(n-i))){
                cout << n << " = " << i << " + " << n-i << endl;
                inside=true;
                break;
            }
        }
        
        if(!inside){
            cout << "Goldbach's conjecture is wrong." << endl;
        }
        inside =false;
        cin >> n;
    }
    return 0;
}
