//Steven Kester Yuwono - UVa 657

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 55
using namespace std;

char field[MAX][MAX];
int width, height;
int countPoint;

vector<int> answer;

// dfs on X
void dfsx(int w, int h){
	field[w][h] = '*';
	if(w+1 < width){
		if (field[w+1][h]=='X'){
			dfsx(w+1,h);
		}
	}
	if(w-1 >=0 ){
		if (field[w-1][h]=='X'){
			dfsx(w-1,h);
		}
	}
	if(h+1 < height){
		if (field[w][h+1]=='X'){
			dfsx(w,h+1);
		}
	}
	if(h-1 >= 0){
		if (field[w][h-1]=='X'){
			dfsx(w,h-1);
		}
	}
}

// dfs on normal face
void dfs(int w, int h){
	field[w][h] = '.';
	if(w+1 < width){
		if (field[w+1][h]=='*'){
			dfs(w+1,h);
		}
		else if (field[w+1][h]=='X'){
			dfsx(w+1,h);
			countPoint++;
			dfs(w+1,h);
		}
	}
	if(w-1 >=0 ){
		if (field[w-1][h]=='*'){
			dfs(w-1,h);
		}
		else if (field[w-1][h]=='X'){
			dfsx(w-1,h);
			countPoint++;
			dfs(w-1,h);
		}
	}
	if(h+1 < height){
		if (field[w][h+1]=='*'){
			dfs(w,h+1);
		}
		else if (field[w][h+1]=='X'){
			dfsx(w,h+1);
			countPoint++;
			dfs(w,h+1);
		}
	}
	if(h-1 >= 0){
		if (field[w][h-1]=='*'){
			dfs(w,h-1);
		}
		else if (field[w][h-1]=='X'){
			dfsx(w,h-1);
			countPoint++;
			dfs(w,h-1);
		}
	}
}

int main(){
	int caseNum = 1;
	cin >> width >> height;
	while(!((width==0)&&(height==0))) {
		answer.clear();
		for (int i=0; i<height; i++) {
			for (int j=0; j<width; j++) {
				cin >> field[j][i];
			}
		}

		// general case
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++) {
				if(field[j][i] == '*'){
					countPoint = 0;
					dfs(j,i);
					answer.push_back(countPoint);
				}
			}
		}

		// corner cases when only X appears on a die face
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++) {
				if(field[j][i] == 'X'){
					countPoint = 0;
					dfsx(j,i);
					answer.push_back(1);
				}
			}
		}

		sort(answer.begin(),answer.end());

		cout << "Throw " << caseNum << endl;
		for (int i=0;i<(int)answer.size();i++){
			if(i!=0){
				cout << " ";
			}
			cout << answer[i];
		}
		cout << endl << endl;

		caseNum++;
		cin >> width >> height;
	}
	return 0;
}