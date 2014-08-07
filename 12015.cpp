#include <iostream>
using namespace std;

int main(){
    string url[10];
    int priority[10];
    int index[10];
    int freq=0;
    int max=0;
    int n;
    string temp;
    cin >> n;
    getline(cin,temp);
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            getline(cin,url[j],' ');
            cin >> priority[j];
            getline(cin,temp);
        }
        
        for(int j=0;j<10;j++){
            if(max<priority[j]){
                max=priority[j];
                index[0]=j;
                freq=1;
            }
            else if (max==priority[j]){
                index[freq++]=j;
            }
        }
        
        cout << "Case #" << i << ":" <<endl;
        for(int i=0;i<freq;i++){
            cout << url[index[i]] << endl;
        }
        
        freq=0;
        max=0;
        
    }
    return 0;
}