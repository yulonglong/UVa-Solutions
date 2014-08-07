//11679 - Sub-prime

#include <iostream>
using namespace std;

bool valid(int reserve[], int B){
	for(int i=0;i<B;i++){
		if(reserve[i]<0){
			return false;
		}
	}
	return true;
}

int main(){
	int B;
	int N;
	int reserve[20];
	int C;
	int D;
	int V;
	for(int i=0;i<20;i++){
		reserve[i]=0;
	}
	
	cin >> B >> N;
	while(!((B==0)&&(N==0))){
		for(int i=0;i<B;i++){
			cin >> reserve[i];
		}
		for(int i=0;i<N;i++){
			cin >> D >> C >> V;
			reserve[C-1]=reserve[C-1]+V;
			reserve[D-1]=reserve[D-1]-V;
		}
		
		if(valid(reserve,B)){
			cout << "S" << endl;
		}
		else{
			cout << "N" << endl;
		}
		
		for(int i=0;i<20;i++){
			reserve[i]=0;
		}
		cin >> B >> N;
	}
	
	
	return 0;
}
