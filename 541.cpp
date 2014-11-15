//Steven Kester Yuwono - UVa 541

#include <iostream>
#include <cstring>
#define MAX 110
using namespace std;

int matrix[MAX][MAX];
int row[MAX];
int column[MAX];

int validateOdd(int arr[MAX], int size){
	int counter = 0;
	int index = 0;
	for(int i=0;i<size;i++){
		if(arr[i]%2==1){
			if(counter==0){
				counter++;
				index = i;
			}
			else if(counter>=1){
				return -1;
			}
		}
	}
	return index;
}


int main(){
	int size;
	cin >> size;
	while(size>0){
		memset(matrix,0,sizeof(matrix));
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));

		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cin >> matrix[i][j];
			}
		}

		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				row[i] += matrix[i][j];
				column[i] += matrix[j][i];
			}
		}

		int index1 = validateOdd(row,size);
		int index2 = validateOdd(column,size);

		if((index1==0)&&(index2==0)){
			cout << "OK" << endl;
		}
		else if((index1==-1)||(index2==-1)){
			cout << "Corrupt" << endl;
		}
		else{
			cout << "Change bit (" << index1+1 << "," << index2+1 << ")" << endl;
		}

		cin >> size;
	}

	return 0;
}