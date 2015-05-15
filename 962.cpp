// Steven Kester Yuwono - UVa 962

#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#define MAX 1000100005
using namespace std;

vector<int> cube;
vector<int> ans;
map<int,int> m;

void init() {
	for(int i=1;i<=1000;i++){
		cube.push_back(i*i*i);
	}
	for(int i=0;i<(int)cube.size();i++){
		for(int j=i+1;j<(int)cube.size();j++){
			if(cube[i]+cube[j]>MAX) break;
			m[cube[i]+cube[j]]++;
		}
	}
	map<int,int>::iterator it;
	for(it = m.begin();it!=m.end();it++){
		if(it->second >= 2)
			ans.push_back(it->first);
	}
}

int main(){
	init();
	int lower, range;
	while (scanf("%d %d",&lower,&range)==2) {
		int l = lower_bound(ans.begin(),ans.end(),lower) - ans.begin();
		bool haveAns = false;
		while(l<ans.size()) {
			if(ans[l] > lower+range) break;
			printf("%d\n",ans[l]);
			haveAns = true;
			l++;
		}

		if(!haveAns){
			printf("None\n");
		}
	}
}