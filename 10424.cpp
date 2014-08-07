//Steven Kester Yuwono - UVa 10424

#include <iostream>
#include <cstdio>
using namespace std;

int getValue(char a){
    a=tolower(a);
    if ((a>='a')&&(a<='z')){
        return a-96;
    }
    return 0;
}

int getFinalValue(string word){
    int subtotal=0;
    for(int i=0;i<word.length();i++){
        subtotal+=getValue(word[i]);
    }
    
    int total=subtotal;
    while(total>9){
        subtotal=total;
        total=0;
        while(subtotal>0){
            total+=subtotal%10;
            subtotal=subtotal/10;
        }
    }
    return total;
}

int main(){
    double result=0;
    string word1;
    string word2;
    while(getline(cin,word1)){
        getline(cin,word2);
        result = (double)getFinalValue(word1)/getFinalValue(word2);
        if(result>1){
            result=(double)getFinalValue(word2)/getFinalValue(word1);
        }
        result=result*100;
        printf("%.2f %%\n",result);
    }
    return 0;
}
