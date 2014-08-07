#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int S;
	int R;
	int diff;
}packet;


bool myfunction (packet a, packet b) {
	return (a.diff<b.diff);
}


int main(){
	int N,G;
	while(scanf("%d %d",&N,&G) == 2){
		vector<packet> array;
		for(int i=0;i<N;i++){
			int S,R;
			scanf("%d %d",&S,&R);
			packet temp;
			temp.S=S;
			temp.R=R;
			temp.diff=R-S;
			array.push_back(temp);
		}
		sort(array.begin(),array.end(),myfunction);
		
		vector<packet>::iterator it;
		int points=0;
		for(it=array.begin();it!=array.end();it++){
			if(it->diff<0){
				points+=3;
			}
			else {
				int diff=it->diff;
				if(G>=diff+1){
					G=G-(diff+1);
					points+=3;
				}
				else if(G==diff){
					G=G-diff;
					points+=1;
				}
				else {
					if(diff==0){
						points+=1;
					}
				}
			}
		}
		printf("%d\n",points);
		
	}
	return 0;
}
