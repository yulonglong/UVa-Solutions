#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    double x;
    double y;
    while(scanf("%lf",&x)==1){
        scanf("%lf",&y);
         printf("%.0lf\n",pow(y,1/x));
    }
    return 0;
}