#include <cstdio>
using namespace std;


unsigned long long reverse(unsigned long long number){
    unsigned long long newNum=0;
    while(number>0){
        newNum*=10;
        newNum+=number%10;
        number/=10;
    }
    return newNum;
}


int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        unsigned long long num1, num2,num3;
        scanf("%llu %llu",&num1,&num2);
        num1=reverse(num1);
        num2=reverse(num2);
        num3=num1+num2;
        num3=reverse(num3);
        printf("%llu\n",num3);
    }
    
    return 0;
}