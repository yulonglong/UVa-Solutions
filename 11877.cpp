// Steven Kester Yuwono - UVa 11877
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    while (num != 0) {

        int drank = 0;
        while (num >= 3) {
            int currDrank = num/3;
            num = currDrank + (num%3);
            drank += currDrank;
        }
        if (num == 2) drank +=1;
        printf("%d\n", drank);
        scanf("%d", &num);
    }
    return 0;
}
