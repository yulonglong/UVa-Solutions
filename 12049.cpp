#include <iostream>
#include <algorithm>
using namespace std;

int arr1[10010];
int arr2[10010];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N,M;
        cin >> N >> M;
        for (int i=0;i<N;i++){
            cin >> arr1[i];
        }
        for(int i=0;i<M;i++){
            cin >> arr2[i];
        }
        sort(arr1,arr1+N);
        sort(arr2,arr2+M);
        int count=0;
        int acount=0;
        int bcount=0;
        
        while((acount<N)&&(bcount<M)){
            if(arr1[acount]==arr2[bcount]){
                acount++;
                bcount++;
            }
            else if(arr1[acount]<arr2[bcount]){
                count++;
                acount++;
            }
            else{
                count++;
                bcount++;
            }
        }
        while(acount<N){
            count++;
            acount++;
        }
        while(bcount<M){
            count++;
            bcount++;
        }
        
        cout << count << endl;
        
    }
}