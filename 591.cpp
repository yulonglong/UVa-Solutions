//Steven Kester Yuwono - UVa 591

#include <cstdio>
using namespace std;
 
int main() {
	int n;
	int height[60];
	scanf("%d", &n);
    for(int t=1;n!=0;t++) {
       
        int total=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&height[i]);
            total+=height[i];
        }
        
        int single = total/n;
        int numofmoves = 0;
        for(int i = 0; i < n; i++){
            if(height[i] > single){
				numofmoves += height[i] - single;
			}
		}
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", t, numofmoves);
        
        scanf("%d", &n);
    }
}
