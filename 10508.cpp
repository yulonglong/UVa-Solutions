//Steven Kester Yuwono - UVa 10508

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> intermediate;
vector<bool> flag;
vector<string> starto;
vector<string> endo;

int dist(string word1, string word2){
	int count = 0;
	for(int i=0;i<(int)word1.length();i++){
		if(word1[i]!=word2[i]){
			count++;
		}
	}
	return count;
}

int findIndexDistanceOne(string currString){
	for(int i=0;i<(int)intermediate.size();i++){
		if(!flag[i]){
			if((dist(currString,intermediate[i]))==1){
				flag[i]=true;
				return i;
			}
		}
	}
	return -1;
}


void wordMorph(string start, string end,int size){
	
	starto.clear();
	endo.clear();
	starto.push_back(start);
	endo.push_back(end);

	for(int i=0;i<=size/2;i++){
		int index = -1;
		index = findIndexDistanceOne(starto[i]);
		if(index!=-1){
			starto.push_back(intermediate[index]);
		}
		index = -1;
		index = findIndexDistanceOne(endo[i]);
		if(index!=-1){
			endo.push_back(intermediate[index]);
		}
		
	}
}

int main(){
	int N,M;
	while(cin >> N >> M){
		string temp;
		getline(cin,temp);//dummy getline to clear

		string start;
		getline(cin,start);
		string end;
		getline(cin,end);

		intermediate.clear();
		flag.clear();

		for(int i=0;i<N-2;i++){
			string tempIntermediate;
			getline(cin,tempIntermediate);
			intermediate.push_back(tempIntermediate);
			flag.push_back(false);
		}

		wordMorph(start,end,intermediate.size());

		for(int i=0;i<(int)starto.size();i++){
			cout << starto[i] << endl;
		}
		int startSize = endo.size()-1;
		if(starto[starto.size()-1]==endo[startSize]){
			startSize--;
		}
		for(int i=startSize;i>=0;i--){
			cout << endo[i] << endl;
		}
		
	}
	return 0;
}