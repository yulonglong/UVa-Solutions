//Steven Kester Yuwono - UVa 10855

#include <iostream>
#include <cstring>
#define MAX 500
using namespace std;

char big[MAX][MAX];
char small[MAX][MAX];

void rotateClockwise(char matrix[MAX][MAX], int size){
	char newMatrix[MAX][MAX];
	memset(newMatrix,0,sizeof(newMatrix));
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			newMatrix[i][j] = matrix[size-1-j][i];
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matrix[i][j] = newMatrix[i][j];
		}
	}
	return;
}

bool match(char s[MAX][MAX], char l[MAX][MAX], int sizeS, int sizeL, int x, int y){
	if((x+sizeS>sizeL)||(y+sizeS>sizeL)){
		return false;
	}
	bool valid = true;
	for(int i=0;i<sizeS;i++){
		for(int j=0;j<sizeS;j++){
			if(s[i][j] != l[i+x][j+y]){
				valid = false;
			}
		}
	}
	return valid;
}

void printMatrix(char matrix[MAX][MAX], int size){
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main(){
	int n1, n2;
	while((cin >> n1 >> n2)&&(!((n1==0)&&(n2==0)))){
		for (int i=0;i<n1;i++){
			for(int j=0;j<n1;j++){
				cin >> big[i][j];
			}
		}
		for (int i=0;i<n2;i++){
			for(int j=0;j<n2;j++){
				cin >> small[i][j];
			}
		}

		
		for(int z=0;z<4;z++){
			int count = 0;
			for (int i=0;i<=n1-n2;i++){
				for(int j=0;j<=n1-n2;j++){
					if(match(small,big,n2,n1,i,j)){
						count++;
					}
				}
			}
			if(z==0){
				cout << count;
			}
			else{
				cout << " " << count;
			}
			rotateClockwise(small,n2);
		}
		cout << endl;

	}
	return 0;
}