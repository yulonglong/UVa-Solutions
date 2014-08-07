#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    bool done=false;
    int counter=1;
    string word;
    getline(cin,word);
    while(word!="end"){
        vector < stack<char> > v;
        stack<char> s;
        
        s.push(word[0]);
        v.push_back(s);
        s.pop();
        for(int i=1;i<word.length();i++){
            done=false;
            for(int j=0;j<v.size();j++){
                if(word[i]<=v[j].top()){
                    v[j].push(word[i]);
                    done=true;
                    break;
                }
            }
            if(!done){
                s.push(word[i]);
                v.push_back(s);
                s.pop();
            }
        }
        cout << "Case " << counter << ": " << v.size() << endl;
        
        counter++;
        getline(cin,word);
    }
}