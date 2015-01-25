//Steven Kester Yuwono - UVa 10887

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

vector<string> first;
set<string> s;

char buffer[1000000];

int main(){
	int tc;
	gets(buffer);
	sscanf(buffer,"%d",&tc);
	for(int d=1;d<=tc;d++){
		first.clear();
		s.clear();
		int n, m;
		gets(buffer);
		sscanf(buffer,"%d %d",&n,&m);
		string temp;
		for(int i=0;i<n;i++){
			gets(buffer);
			temp = string(buffer);
			first.push_back(temp);
		}
		for(int i=0;i<m;i++){
			gets(buffer);
			temp = string(buffer);
			for(int j=0;j<(int)first.size();j++){
				string concatenation = first[j] + temp;
				s.insert(concatenation);
			}
		}
		printf("Case %d: %d\n",d, s.size());
	}
	return 0;
}