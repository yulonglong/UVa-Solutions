//Steven Kester Yuwono - UVa 12662

#include <iostream>
using namespace std;

int main(){
	string temp;
	string name[110];
	int numStud;
	cin >> numStud;
	for(int i=0;i<numStud;i++){
		cin >> temp;
		name[i]=temp;
	}
	int numQuery;
	cin >> numQuery;
	while(numQuery--){
		int query;
		int leftOffset=1;
		int rightOffset=1;
		cin >> query;
        query--;
		if(name[query]!="?"){
			cout << name[query] << endl;
		}
		else{
			while((query+leftOffset<numStud)&&(name[query+leftOffset]=="?")){
				leftOffset++;
			}
            if((query+leftOffset)>=numStud){
                leftOffset= 999999;
            }
			while((query-rightOffset>=0)&&(name[query-rightOffset]=="?")){
				rightOffset++;
			}
            if((query-rightOffset)<0){
                rightOffset= 999999;
            }
			if(leftOffset==rightOffset){
				cout << "middle of " << name[query-rightOffset] << " and " << name[query+leftOffset] << endl;	
			}
			else if(rightOffset>leftOffset){
				for(int i=0;i<leftOffset;i++){
					cout << "left of ";
				}
				cout << name[query+leftOffset] << endl;
			}
			else if(leftOffset>rightOffset){
				for(int i=0;i<rightOffset;i++){
					cout << "right of ";
				}
				cout << name[query-rightOffset] << endl;
			}
		}
	}
	return 0;
}