//Steven Kester Y - UVa 12667
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct{
	bool submitted[110];
	int tID;
	int sTime;
}Pair;

int main(){
	Pair temp;
	temp.tID=0;
	temp.sTime=-1;
	Pair array[100];
	for(int i=0;i<100;i++){
		array[i]=temp;
	}

	int n,t,m;
	scanf("%d %d %d",&n,&t,&m);
	for(int i=0;i<m;i++){
		int subTime;
		char verdict[5];
        string verStr;
		int teamID;
		char problem;
		scanf("%d %d %c %s",&subTime,&teamID,&problem,&verdict[0]);
		verStr=verdict;
        if(verStr=="No"){
		}
		else{
			if(!array[problem].submitted[teamID]){
				array[problem].tID=teamID;
				array[problem].sTime=subTime;
				array[problem].submitted[teamID]=true;
			}
		}

	}

	for(int i=0;i<n;i++){
		char tempChar = i +'A';
		if(array[tempChar].tID==0){
			cout << tempChar << " - -" << endl;
		}
		else{
			cout << tempChar << " " << array[tempChar].sTime << " " << array[tempChar].tID << endl;
		}
	}

	return 0;
}