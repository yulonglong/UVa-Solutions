//Steven Kester Yuwono - UVa 512

#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#define MAX 55
using namespace std;

pair<int,int> store[MAX][MAX];
int maxRow;
int maxCol;


void resetArray(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			pair<int,int> newPair(-1,-1);
			store[i][j] = newPair;
		}
	}
}

pair<int,int> findAnswer(int x,int y){
	for(int i=0;i<maxRow;i++){
		for(int j=0;j<maxCol;j++){
			pair<int,int> answer = store[i][j];
			if((answer.first == x)&&(answer.second == y)){
				return pair<int,int>(i+1,j+1);
			}
		}
	}
	return pair<int,int>(-1,-1);
}

void deleteRow(int row){
	row--;
	for(int i=row;i<maxRow;i++){
		for(int j=0;j<maxCol;j++){
			store[i][j] = store[i+1][j];
		}
	}
}

void deleteCol(int col){
	col--;
	for(int i=col;i<maxCol;i++){
		for(int j=0;j<maxRow;j++){
			store[j][i] = store[j][i+1];
		}
	}
}

void insertRow(int row){
	row--;
	for(int i=maxRow;i>row;i--){
		for(int j=0;j<maxCol;j++){
			store[i][j] = store[i-1][j];
		}
	}
	for(int j=0;j<maxCol;j++){
		pair<int,int> newPair(-1,-1);
		store[row][j] = newPair;
	}
}

void insertCol(int col){
	col--;
	for(int i=maxCol;i>col;i--){
		for(int j=0;j<maxRow;j++){
			store[j][i] = store[j][i-1];
		}
	}
	for(int j=0;j<maxRow;j++){
		pair<int,int> newPair(-1,-1);
		store[j][col] = newPair;
	}
}

void print(){
	for(int i=0;i<maxRow;i++){
		for(int j=0;j<maxCol;j++){
			cout << store[i][j].first <<"," << store[i][j].second << " ";
		}
		cout << endl;
	}
}

int main(){
	int tcCounter=1;
	while ((cin >> maxRow >> maxCol) &&(!((maxRow==0)&&(maxCol==0)))) {
		if(tcCounter>1){
			printf("\n");
		}
		resetArray();
		
		for(int i=0;i<maxRow;i++){
			for(int j=0;j<maxCol;j++){
				pair<int,int> newPair(i+1,j+1);
				store[i][j] = newPair;
			}
		}

		int numCommand;
		cin >> numCommand;
		string temp;
		getline(cin,temp); //dummy getline
		for(int d=0;d<numCommand;d++){
			string line;
			getline(cin,line);
			istringstream istream(line);
			string command;
			istream >> command;

			vector<int> q;
			q.clear();

			int numExec;
			istream >> numExec;
			if(command == "EX"){
				int numExec2, set1,set2;
				istream >> numExec2 >> set1 >> set2;
				swap(store[numExec-1][numExec2-1],store[set1-1][set2-1]);
				continue;
			}
			else {
				for(int i=0;i<numExec;i++){
					int temp;
					istream >> temp;
					q.push_back(temp);
				}
			}

			sort(q.begin(),q.end());

			vector<int>::iterator it;
			int counter = 0;
			for(it = q.begin(); it!=q.end();it++){
				if(command == "DR"){
					deleteRow(*it - counter);
					maxRow--;
				}
				else if(command == "DC") {
					deleteCol(*it - counter);
					maxCol--;
				}
				else if(command == "IR") {
					insertRow(*it + counter);
					maxRow++;
				}
				else if(command == "IC") {
					insertCol(*it + counter);
					maxCol++;
				}
				counter++;
				//cout << *it << endl;
				//print();
			}
		}

		printf("Spreadsheet #%d\n",tcCounter++);

		int numCommand2;
		cin >> numCommand2;
		for(int d=0;d<numCommand2;d++){
			int x,y;
			cin >> x >> y;
			pair<int,int> answer = findAnswer(x,y);

			if((answer.first == -1)&&(answer.second == -1)) {
				printf("Cell data in (%d,%d) GONE\n",x,y);
			}
			else {
				printf("Cell data in (%d,%d) moved to (%d,%d)\n",x,y,answer.first,answer.second);
			}
		}
	}
}