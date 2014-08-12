//Steven Kester Yuwono - UVa 11875

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int d=1;d<=tc;d++){
        int n;
        cin >> n;
        int arr[12];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        
        cout << "Case "<< d << ": " << arr[n/2] << endl;
    }
    return 0;
}