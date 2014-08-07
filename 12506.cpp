//Steven Kester Yuwono - UVa 12506

#include <bits/stdc++.h>
using namespace std;

set<string> store;

int getIndex (string a, string b){
    int i=0;
    int lenA=a.length();
    int lenB=b.length();
    while((i<lenA)&&(i<lenB)&&(a[i]==b[i])){
        i++;
    }
    i++;
    return i;
}

int main(){
    string word;
    int tc,n;
    getline(cin,word);
    tc=atoi(word.c_str());
    while(tc--){
        store.clear();
        getline(cin,word);
        n=atoi(word.c_str());
        for(int i=0;i<n;i++){
            getline(cin,word);
            store.insert(word);
        }
        
        set<string>::iterator it;
        it=store.begin();
        string prev,curr;
        int prevIndex=0;
        int currIndex=0;;
        int counter=0;
        prev = *it;
        it++;
        for(;it!=store.end();it++){
            curr = *it;
            currIndex = getIndex(prev,curr);
            if(currIndex>prevIndex){
                counter+=currIndex;
            }
            else{
                counter+=prevIndex;
            }
            prevIndex=currIndex;
            prev=curr;
        }
        counter += prevIndex;
        
        cout << counter << endl;
        
        
    }

}