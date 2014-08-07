#include <cstdio>
using namespace std;

int main(){
    int counter=1;
    bool visited=false;
    int N;
    scanf("%d",&N);
    while(N!=0){
        if(counter>1){
            printf("\n");
        }
        counter++;
        visited=false;
        for (int fghij =1234; fghij <= 98765 / N ; fghij++){
            int abcde = fghij *N;
            int tmp;
            int used = (fghij<10000);
            tmp = abcde;
            while(tmp){
                used |= 1<< (tmp%10);
                tmp/=10;
            }
            tmp = fghij;
            while(tmp){
                used |= 1<< (tmp%10);
                tmp/=10;
            }
            if(used== (1<<10)-1){
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
                visited=true;
            }
          
        }
        if(!visited){
            printf("There are no solutions for %d.\n",N);
        }
        scanf("%d",&N);

      
        
    }
    return 0;
}