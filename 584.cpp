//Steven Kester Yuwono - UVa 584 - Bowling

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int getIntValue(char tempChar){
	if ((tempChar>='0')&&(tempChar<='9')){
		return tempChar-'0';
	}
	return -1;
}

void calcScore(char score[], int scoreInt[], int round[],int total){
	int number=0;
	int roundNum=0;
	int tempScore=0;
	for(int i=0;i<total;i++){
		tempScore=getIntValue(score[i]);
		if(number==0){
			roundNum++;
		}
		
		if(tempScore>=0){
			scoreInt[i]=tempScore;
			if(number==0){
				number++;
			}
			else{
				number=0;
			}
			round[i]=roundNum;
		}
		else{
			number=0;
			round[i]=roundNum;
			if(score[i]=='/'){
				scoreInt[i]=10-getIntValue(score[i-1]);
			}
			else if(score[i]=='X'){
				scoreInt[i]=10;
			}
		}
	}
}


int main(){
	int ans=0;
	char score[30];
	int scoreInt[30];
	int round[30];
	for(int i=0;i<30;i++){
		score[i]='0';
		scoreInt[i]=0;
		round[i]=0;
	}
	string temp;
	int tempScore;
	
	getline(cin,temp);
	while(temp!="Game Over"){
		istringstream istream(temp);
		int i=0;
		while(istream>>score[i++]){
		}
		calcScore(score, scoreInt,round, i);
		for(int j=0;j<i;j++){
			tempScore=getIntValue(score[j]);
			//cout << tempScore << endl;
			if(tempScore>=0){
				ans+=tempScore;
			}
			else{
				if(score[j]=='/'){
					tempScore=scoreInt[j];
					if(round[j]<10){
						tempScore+=scoreInt[j+1];
					}
					ans+=tempScore;
				}
				else if(score[j]=='X'){
					tempScore=scoreInt[j];
					if(round[j]<10){
						tempScore+=scoreInt[j+1];
						tempScore+=scoreInt[j+2];
					}
					ans+=tempScore;
				}
			}
		}
		
		cout << ans << endl;
		/*
		for(int i=0;i<30;i++){
			cout << score[i]<< " ";
		}
		cout <<endl;
		for(int i=0;i<30;i++){
			cout << scoreInt[i] << " ";
		}
		cout <<endl;
		for(int i=0;i<30;i++){
			cout << round[i] << " ";
		}
		*/
		
		for(int i=0;i<30;i++){
			score[i]='0';
			scoreInt[i]=0;
			round[i]=0;
		}
		ans=0;
		getline(cin,temp);
	}
	return 0;
}
