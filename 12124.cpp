//Steven Kester Yuwono - UVa 12124

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef struct{
	int q;
	int p;
}parts;

map<string,int> name;
vector<parts> components[1010];
int intType=0;


bool valid(int q, int budget){
	int sum=0;
	int maxType=name.size();
	for(int i=0;i<maxType;i++){
		int minp=1000005;
		for(unsigned int j=0;j<components[i].size();j++){
			if( components[i][j].q>=q){
				minp=min(minp,components[i][j].p);
			}
		}
		sum+=minp;
	}
	if (sum>budget){
		return false;
	}
	return true;
}


int getType(string type){
	map<string,int>::iterator it;
	it=name.find(type);
	if (it==name.end()){
		name.insert(pair<string,int>(type,intType));
		return intType++;
	}
	else{
		return it->second;
	}
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, budget,p,q;
		cin >> N >> budget;
		string type ="";
		int minq=1000000005;
		int maxq=0;
		string temp;
		
		for(unsigned int i=0;i<1010;i++){
			components[i].clear();
		}
		name.clear();
		intType=0;
		
		while(N--){
			cin >> type >> temp >> p >> q;
			parts tempParts;
			tempParts.q=q;
			tempParts.p=p;
			components[getType(type)].push_back(tempParts);
			minq=min(minq,q);
			maxq=max(maxq,q);
			
		}
		
		int mid=0;
		
		int L = minq;
		int R = maxq;
		while(L<R){
			mid= (L+R+1)/2;
			if(valid(mid,budget)){
				L=mid;
			}
			else{
				R=mid-1;
			}
		}
		cout << L << endl;
		
		
	}
	return 0;
}
