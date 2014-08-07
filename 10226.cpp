//Steven Kester Yuwono - UVa 10226

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

int main(){
    
    map<string,int>::iterator it;
    string word;
    int tc;
    cin >> tc;
    getline(cin,word);
    getline(cin,word);
    for(int d=0;d<tc;d++){
        map<string,int> mymap;
        
        int size=0;
        
        
        while(getline(cin,word)){
            if(word==""){
                break;
            }
            size++;
            it=mymap.find(word);
            if(it!=mymap.end()){
                it->second+=1;
            }
            else{
                mymap.insert(pair<string,int>(word,1));
            }
        }
        
        if(d>0){
            printf("\n");
        }
        for(it=mymap.begin();it!=mymap.end();it++){
            double result=(double)(it->second)/(double)size;
            result*=100;
            printf("%s %.4f\n",(it->first).c_str(),result);
        }
    }
}