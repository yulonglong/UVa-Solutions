//696 - How Many Knights

#include <iostream>
using namespace std;

int main(){
	int M;
	int N;
	int ans=0;
	int temp=0;
	cin >> M >> N;
	while(!((M==0)&&(N==0))){
		if ((M>=3)&&(N>=3)){
			ans= ((N*M)+1)/2;
		}
		else if(M==1){
			ans=N;
		}
		else if(N==1){
			ans=M;
		}
		else if(M==2){
			temp=(N/2);
			if(((temp%2)==1)||((N%2)==1)){
				temp=(N+2)/2;
			}
			ans=temp*2;
		}
		else if(N==2){
			temp=(M/2);
			if(((temp%2)==1)||((M%2)==1)){
				temp=(M+2)/2;
			}
			ans=temp*2;
		}
		
		cout << ans << " knights may be placed on a " << M << " row " << N << " column board." << endl;	
		cin >> M >> N;
	}
	return 0;
}
