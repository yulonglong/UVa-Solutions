#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int c[15][15];
int m[15];
int vis[15][15];

void print(int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    print(i, vis[i][j]);
    printf(" x ");
    print(vis[i][j] + 1, j);
    printf(")");
}

int main(){
    int n;
    int t=1;
    scanf("%d",&n);
    while(n>0){
         int counter=0;
        int a,b;
        scanf("%d %d",&a,&b);
        m[counter++]=a;
        m[counter++]=b;
        for(int i=1;i<n;i++){
             scanf("%d %d",&a,&b);
            m[counter++]=b;
        }
        /*
        for(int i=1;i<=n+1;i++){            cout << m[i] << endl;

        }*/
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                c[i][j]=2000000000;
            }
            c[i][i]=0;
        }
        for(int s=1;s<=n-1;s++){
            for(int i=1;i<=n-s;i++){
                int j=i+s;
                for(int k=i;k<j;k++){
                    int temp=c[i][k]+c[k+1][j]+(m[i-1]*m[k]*m[j]);
                    //cout << "S" << temp<< endl;
                    if (c[i][j]>temp){
                        c[i][j]=temp;
                        vis[i][j]=k;
                    }
                }
            }
        }
        
        printf("Case %d: ",t++);
        //printf("%d\n",c[1][n]);
        print(1, n);
        printf("\n");
        
        scanf("%d",&n);

    }
    return 0;
}