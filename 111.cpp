//Steven Kester Yuwono - UVa 111
//Longest Increasing Subsequence (LIS) - Dynamic Programming

#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;

map<int,int> m;
map<int,int>::iterator it1, it2;
int input[22];
int memo[22];
int N;

int getLIS(){
	memset(memo,-1,sizeof(memo));
	memo[1]=1;
	int bestLIS=1;
	int bestIndex=1;
	for(int i=2;i<=N;i++){
		bestIndex=1;
		it1 = m.find(input[i]);
		int currValue = it1->second;
		for(int j=i-1;j>=1;j--){
			it2 = m.find(input[j]);
			int targetValue = it2->second;
			if(targetValue<currValue){
				if(bestIndex < memo[j] + 1){
					bestIndex = memo[j] + 1; 
				}
			}
		}
		memo[i] = bestIndex;
		bestLIS = max(memo[i],bestLIS);
	}
	return bestLIS;
}

void convertRankToOrder(){
	map<int,int> tempMap;
	for(int i=1;i<=N;i++){
		tempMap.insert(pair<int,int>(input[i],i));
	}
	it1=tempMap.begin();
	for(int i=1;i<=N;i++){
		input[i]=it1->second;
		it1++;
	}
	return;
}

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		int temp;
		cin >> temp;
		m.insert(pair<int,int>(i,temp));
	}
	string tempStr;
	getline(cin,tempStr); // remove dummy line
	while(getline(cin,tempStr)){
		memset(input,0,sizeof(input));
		
		istringstream istream(tempStr);
		for(int i=1;i<=N;i++){
			istream >> input[i];
		}
		convertRankToOrder();
		cout << getLIS() << endl;
	}
	return 0;
}