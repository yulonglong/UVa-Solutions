//Steven Kester Yuwono - UVa 11176
#include <bits/stdc++.h>
#define MAX 510
using namespace std;

double t[MAX];
double memo[MAX][MAX];  

int main () {  
	int n;  
	double p;
	
	
    while (scanf("%d %lf", &n, &p)&&(n!=0)){  
		t[0] = 1;  
		memset(memo, 0, sizeof(memo));
		for(int i=0;i<=n;i++) {  
			memo[0][i]=1;  
			t[i+1]=p*t[i];  
		}  
		for (int i=1;i<=n;i++) {  
			for (int j=0;j<=n;j++) {  
				memo[i][j]=memo[i-1][j];  
				if(i==j+1){  
					memo[i][j]-=t[j+1];  
				}
				else if (i>j+1){
					memo[i][j]-=memo[i-j-2][j]*(1-p)*t[j+1];  
				}
			}
		}
		double answer = 0;  
		for (int i=1;i<=n;i++){
			answer+=(memo[n][i]-memo[n][i-1])*i;  
		}
		printf("%.6lf\n", answer);  	
    }  
    return 0;  
} 
