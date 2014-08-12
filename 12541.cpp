//Steven Kester Yuwono - UVa 12541

#include <iostream>
#include <map>
using namespace std;

map<int,string> mp;

int main(){
    mp.clear();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        int d,m,y;
        cin >> d>> m >>y;
        int total = y*1000 + m*13 + d;
        mp.insert(pair<int,string>(total,name));
    }
    
    map<int,string>::reverse_iterator it2;
    map<int,string>::iterator it;
    it2=mp.rbegin();
    cout << it2->second << endl;
    it=mp.begin();
    cout << it->second << endl;
    
    return 0;
}
