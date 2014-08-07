//Steven Kester Yuwono - UVa 10776

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


void permutate2(int letter,int num,int index,int use, string result){
    if(num==0){
        printf("%s\n",result.c_str());
        return;
    }

    
    if(letter[tempIndex]>tempUse){
        use++;
        char tempChar=index;
        result=result+tempChar;
        num--;
        
    }
    else {
        return;
    }
}



void permutate(int letter[], int num){
    int tempNum=num;
    int tempIndex='a';
    int tempUse=0;
    string result;
    for(int i='a';i<='z';i++){
        tempNum=num;
        tempUse=0;
        result="";
        tempIndex='a';
       
    }
}


int main(){
    int letter[200]={0};
    string word;
    int num;
    string numString;
    while (getline(cin,word,' ')){
        getline(cin,numString);
        num=atoi(numString.c_str());
        for(int i=0;i<word.length();i++){
            letter[word[i]]++;
        }
        permutate(letter,num);
    }
    return 0;
}