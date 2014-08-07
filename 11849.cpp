#include <cstdio>
#include <set>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while((n!=0)&&(m!=0)){
        int count=0;
        set<int> myset;
        while(n--){
            int num;
            scanf("%d",&num);
            myset.insert(num);
        }
        while(m--){
            int num;
            scanf("%d",&num);
            set<int>::iterator it;
            it=myset.find(num);
            if(it!=myset.end()){
                count++;
            }
        }
        printf("%d\n",count);
        scanf("%d %d",&n,&m);
    }
}