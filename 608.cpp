//608 - Counterfeit Dollar

#include <iostream>
#include <string>
using namespace std;

int main(){
	int up[100];
	int down[100];
	for(int i=0;i<100;i++){
		up[i]=0;
		down[i]=0;
	}
	string temp;
	string command[3];
	char ans;
	bool heavy=true;
	int n;
	cin>> n;
	getline(cin,temp);
	while(n--){
		for(int i=0;i<3;i++){
			getline(cin,command[0],' ');
			getline(cin,command[1],' ');
			getline(cin,command[2]);
			
			if(command[2]=="even"){
				int len=command[0].length();
				for(int j=0;j<len;j++){
					up[command[0][j]]=-3;
					down[command[0][j]]=-3;
					up[command[1][j]]=-3;
					down[command[1][j]]=-3;
				}
			}
			else if	(command[2]=="up"){
				int len=command[0].length();
				for(int j=0;j<len;j++){
					down[command[0][j]]++;
					up[command[1][j]]++;
				}
			}
			else if	(command[2]=="down"){
				int len=command[0].length();
				for(int j=0;j<len;j++){
					up[command[0][j]]++;
					down[command[1][j]]++;
				}
			}
		}
		/*
		cout << save[0] << endl;
		cout << save[1] << endl;
		cout << save[2] << endl;
		for(int i=65;i<=76;i++){
			cout << coins[i] << endl;
		}*/
		int max=-5;
		for(int i=65;i<=76;i++){
			if(max<up[i]){
				max=up[i];
				ans=i;
				heavy=false;
			}
			if(max<down[i]){
				max=down[i];
				ans=i;
				heavy=true;
			}
		}
	
		if(heavy){
			cout << ans << " is the counterfeit coin and it is heavy." << endl;
		}
		else{
			cout << ans << " is the counterfeit coin and it is light." << endl;
		}
		
		
		for(int i=63;i<93;i++){
			up[i]=0;
			down[i]=0;
		}
	}
	
	return 0;
}
