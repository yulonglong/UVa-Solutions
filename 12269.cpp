#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

bool complete(int n,double w,double width){
    double mow[1010];
    for(int i=0;i<n;i++){
        scanf("%lf",&mow[i]);
    }
    sort(mow,mow+n);
    if(mow[0]>w/2){
        return false;
    }
    else if (width-mow[n-1]>w/2){
        return false;
    }
    else{
        for(int i=1;i<n;i++){
            if(mow[i]-mow[i-1]>w){
                return false;
            }
        }
    }
    
    return true;
}

int main(){
    int n1,n2;
    double w;
    scanf("%d %d %lf",&n1,&n2,&w);
    

    while((n1!=0)&&(n2!=0)&&(w!=0)){
        bool b1=complete(n1,w,75.0);
        bool b2=complete(n2,w,100.0);
        
        if(b1&&b2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
        
        scanf("%d %d %lf",&n1,&n2,&w);
    }
}

