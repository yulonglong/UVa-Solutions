#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int num[10001];
    int medianindex=0;
    int counter=0;
    int n;
    while(scanf("%d",&n)==1){
        num[counter++]=n;
        sort(num,num+counter);
        if(counter%2==1){
            medianindex=counter/2;
            cout << num[medianindex] << endl;
        }
        else{
            medianindex=(counter/2);
            cout << (num[medianindex-1]+num[medianindex])/2 << endl;
        }
    }
    return 0;
}