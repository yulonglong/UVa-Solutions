//Steven Kester Yuwono - UVa 427

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define halfPI acos(-1.0)/2.0

bool check(double wid, double len, double first, double second){
	double y = 0;
	double maximumWid = 1e30;
	if ((wid>first)||(wid>second)){
		return false;
	}
	for (double i=0;i<halfPI;i+=0.01) {
		y = first*sin(i) + second*cos(i) - (0.5*len*sin(2*i));
		maximumWid = min(y,maximumWid);
	}
	if (wid < maximumWid){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string word;
	string word1;
	string word2;
	while(getline(cin,word)){
		istringstream istream(word);
		getline(istream,word1,',');
		getline(istream,word2,' ');
		int pLen = atoi(word1.c_str());
		int pWid = atoi(word2.c_str());
		if(pWid>pLen){
			swap(pWid,pLen);
		}
		while(getline(istream,word1,',')){
			getline(istream,word2,' ');
			int cFirst = atoi(word1.c_str());
			int cSecond = atoi(word2.c_str());
			if(check(pWid,pLen,cFirst,cSecond)){
				printf("Y");
			}
			else{
				printf("N");
			}
		}
		printf("\n");
	}
	return 0;
}
