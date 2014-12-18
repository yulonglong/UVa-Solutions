//Steven Kester Yuwono - UVa 467

#include <cstdio>
#include <iostream>
#include <sstream>
#define MAX 10
#define MAXTIME 3600
using namespace std;

int signal[MAX];
char simu[MAX][MAXTIME+1];

void simulate(int n){
	for(int i=0;i<n;i++){
		int curr = 0;
		while(curr<=MAXTIME){
			for(int j=curr;(j<signal[i]+curr-5)&&(j<=MAXTIME);j++){
				simu[i][j] = 'G';
			}
			for(int j=signal[i]+curr-5;(j<signal[i]+curr)&&(j<=MAXTIME);j++){
				simu[i][j] = 'Y';
			}
			curr += signal[i];
			for(int j=curr;(j<signal[i]+curr)&&(j<=MAXTIME);j++){
				simu[i][j] = 'R';
			}
			curr += signal[i];
		}
	}
}

int firstGreen(int n){
	bool firstYellow = false;
	for(int t=0;t<=MAXTIME;t++){
		bool allGreen = true;
		for(int i=0;i<n;i++){
			if(simu[i][t]!='G'){
				firstYellow = true;
				allGreen = false;
				break;
			}
		}
		if(allGreen&&firstYellow){
			return t;
		}
	}
	return -1;
}

int main(){
	string line;
	int tc = 1;
	while(getline(cin,line)){
		istringstream istream(line);
		int cycle;
		int i = 0;
		while(istream >> cycle){
			signal[i++] = cycle;
		}
		simulate(i);

		int answerSeconds = firstGreen(i);
		if(answerSeconds>0){
			printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",tc,answerSeconds/60,answerSeconds%60);
		}
		else{
			printf("Set %d is unable to synch after one hour.\n",tc);
		}
		tc++;
	}
	return 0;
}