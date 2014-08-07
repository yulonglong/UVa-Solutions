#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

int LSOne(int i){
    return (i)&(-i);
}

class FenwickTree{
private:
    vi ft;
public:
    FenwickTree(int n){
        ft.assign(n+1,0);
    }
    int rsq(int a){
        int sum=0;
        for(;a>0;a-=LSOne(a)){
            sum+=ft[a];
        }
        return sum;
    }
    int rsq(int a, int b){
        if(a==1){
            return rsq(b);
        }
        return rsq(b)-rsq(a-1);
    }
    void adjust(int k,int v){
        for(;k<(int)ft.size();k+=LSOne(k)){
            ft[k]+=v;
        }
    }
    
};

int main(){
    int counter=1;
    int n;
    scanf("%d",&n);
    while(n>0){
        FenwickTree ft(n);
        for(int i=1;i<=n;i++){
            int value;
            scanf("%d",&value);
            ft.adjust(i,value);
        }
        
        if(counter>1){
            printf("\n");
        }
        printf("Case %d:\n",counter++);
        
        char command[4];
        int index;
        int value;
        scanf("%s",&command[0]);
        while(command[0]!='E'){
            if(command[0]=='M'){
                scanf("%d %d",&index,&value);
                printf("%d\n",ft.rsq(index,value));
            }
            else if(command[0]=='S'){
                scanf("%d %d",&index,&value);
                int temp= 0;
                temp = ft.rsq(index,index);
                temp=temp*-1;
                ft.adjust(index,temp);
                ft.adjust(index,value);
            }
            scanf("%s",&command[0]);
        }
        scanf("%d",&n);
    }
   
    
    return 0;
}