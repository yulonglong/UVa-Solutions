#include <iostream>
#include <stack>
using namespace std;

int main(){
    bool valid=true;
    stack<char> s;
    string word;
    int n;
    cin >> n;
    getline(cin,word);
    while(n--){
        getline(cin,word);
        for(int i=0;i<word.length();i++){
            if((word[i]=='[')||(word[i]=='(')){
                s.push(word[i]);
            }
            else if(word[i]==']'){
                if((!s.empty())&&(s.top()=='[')){
                    s.pop();
                }
                else{
                    valid=false;
                    break;
                }
            }
            else if(word[i]==')'){
                if((!s.empty())&&(s.top()=='(')){
                    s.pop();
                }
                else{
                    valid=false;
                    break;
                }
            }
        }
        
        if((valid)&&(s.size()==0)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        valid=true;
        while(!s.empty()){
            s.pop();
        }
    }
    return 0;
}