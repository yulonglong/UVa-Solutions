// 12247 - Jollo

#include <algorithm>
#include <iostream>
using namespace std;

bool win(int a, int b){
	if (a>b){
		return true;
	}
	return false;
}

int main(){
	bool chosen[53];
	for(int i=0;i<53;i++){
		chosen[i]=false;
	}
	int tempInt=0;
	int a[3];
	int x[2];
	bool abool[3];
	bool xbool[2];
	bool tempsecond=false;
	int princess=0;
	cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1];
	while(!((a[0]==0)&&(a[1]==0)&&(a[2]==0)&&(x[0]==0)&&(x[1]==0))){
		sort(a, a+3);
		sort(x, x+2);
		chosen[a[0]]=true;
		chosen[a[1]]=true;
		chosen[a[2]]=true;
		chosen[x[0]]=true;
		chosen[x[1]]=true;
		
		if(win(a[0],x[1])){
			//cout << "A" << endl;
			princess++;
			abool[0]=true;
			xbool[1]=true;
		}
		else if(win(a[1],x[1])){
			//cout << "B" << endl;
			princess++;
			abool[1]=true;
			xbool[1]=true;
		}
		else if(win(a[2],x[1])){
			//cout << "C" << endl;
			princess++;
			abool[2]=true;
			xbool[1]=true;
		}
		tempsecond=false;
		if(!abool[0]){
			if(win(a[0],x[0])){
				//cout << "D" << endl;
				tempsecond=true;
				princess++;
				abool[0]=true;
				xbool[0]=true;
			}
		}
		if (!tempsecond){
			if(!abool[1]){
				if(win(a[1],x[0])){
					//cout << "E" << endl;
					tempsecond=true;
					princess++;
					abool[1]=true;
					xbool[0]=true;
				}
			}
		}
		if (!tempsecond){
			if(!abool[2]){
				if(win(a[2],x[0])){
					//cout << "F" << endl;
					princess++;
					abool[2]=true;
					xbool[0]=true;
				}
			}
		}
		
		if(princess==2){
			cout << "-1" << endl;
		}
		else if(princess==1){
			if(!abool[2]){
				tempInt=a[2];
				while((chosen[tempInt]==true)&&(tempInt<53)){
					tempInt++;
				}
				if(tempInt<53){
					cout << tempInt << endl;
					chosen[tempInt]=true;
				}
				else{
					cout << "-1" << endl;
				}
			}
			else if(!abool[1]){
				tempInt=a[1];
				while((chosen[tempInt]==true)&&(tempInt<53)){
					tempInt++;
				}
				if(tempInt<53){
					cout << tempInt << endl;
					chosen[tempInt]=true;
				}
				else{
					cout << "-1" << endl;
				}
			}
		}
		else{
			tempInt=1;
			while((chosen[tempInt]==true)&&(tempInt<53)){
				tempInt++;
			}
			if(tempInt<53){
				cout << tempInt << endl;
				chosen[tempInt]=true;
			}
		}
		
		
		for(int i=0;i<53;i++){
			chosen[i]=false;
		}
		tempsecond=false;
		tempInt=0;
		princess=0;
		abool[0]=false;
		abool[1]=false;
		abool[2]=false;
		xbool[0]=false;
		xbool[1]=false;
		cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1];
	}
	return 0;
}
