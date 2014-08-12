//Steven Kester Yuwono - UVa 11824

#include <cstdio>
#include <set>
#include <cmath>
using namespace std;

set<int> s;

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        s.clear();
        int temp;
        int total=0;
        scanf("%d",&temp);
        while(temp!=0){
            s.insert(temp);
             scanf("%d",&temp);
        }
        set<int>::reverse_iterator it;
        int counter=1;
        for(it=s.rbegin();it!=s.rend();it++){
            int num = *it;
            total=total+(2*pow(num,counter));
            counter++;
        }
        if(total>5000000){
            printf("Too expensive\n");
        }
        else{
            printf("%d\n",total);
        }
    }
    return 0;
}