//Steven Kester Yuwono - UVa 173

#include <bits/stdc++.h>
using namespace std;

int getInt(char chara){
	return (int)chara-'A';
}

char getChar(int inta){
	return  (char)(inta+'A');
}

vector<int> adjList[27];
bool visitedP[27];
bool visitedL[27];

int moveP(int curr){
	bool done=false;
	int nextIndex=-1;
	for(unsigned int i=0;i<adjList[curr].size();i++){
		int potIndex=adjList[curr][i];
		if(curr<potIndex){
			if((!visitedP[potIndex])&&(!visitedL[potIndex])){
				nextIndex=potIndex;
				done=true;
				break;
			}
		}
	}
	if(!done){
		for(unsigned int i=0;i<adjList[curr].size();i++){
			int potIndex=adjList[curr][i];
			if((!visitedP[potIndex])&&(!visitedL[potIndex])){
				nextIndex=potIndex;
				done=true;
				break;
			}
			if(curr<potIndex){
				break;
			}
		}
	}
	return nextIndex;
}
	
int moveL(int curr){
	bool done=false;
	int nextIndex=-1;
	for(int i=(adjList[curr].size())-1;i>=0;i--){
		int potIndex=adjList[curr][i];
		//cout << potIndex << endl;
		if(curr>potIndex){
			if(!visitedL[potIndex]){
				nextIndex=potIndex;
				done=true;
				break;
			}
		}
	}
	if(!done){
		for(int i=(adjList[curr].size())-1;i>=0;i--){
			int potIndex=adjList[curr][i];
			if(!visitedL[potIndex]){
				nextIndex=potIndex;
				done=true;
				break;
			}
			if(curr>potIndex){
				break;
			}
		}
	}
	return nextIndex;
}


int main(){
	string word;
	getline(cin,word);
	while(word!="#"){
		memset(visitedP,false,sizeof(visitedP));
		memset(visitedL,false,sizeof(visitedL));
		istringstream istream1(word);
		string word1;
		char startP;
		char startL;
		getline(istream1,word1,' ');
		istream1 >> startP >> startL;
		int intStartP=getInt(startP);
		int intStartL=getInt(startL);
		
		istringstream istream2(word1);
		char from,temp,to;
		
		while(true){
			istream2>>from;
			int intFrom=getInt(from);
			istream2>>temp;
			istream2>>to;
			while((to!=';')&&(to!='.')){
				int intTo=getInt(to);
				
				vector<int>::iterator it;
				it=find(adjList[intFrom].begin(),adjList[intFrom].end(),intTo);
				if(it==adjList[intFrom].end()){
					adjList[intFrom].push_back(intTo);
					sort(adjList[intFrom].begin(),adjList[intFrom].end());
				}
				it=find(adjList[intTo].begin(),adjList[intTo].end(),intFrom);
				if(it==adjList[intTo].end()){
					adjList[intTo].push_back(intFrom);
					sort(adjList[intTo].begin(),adjList[intTo].end());
				}
				istream2>>to;
			}
			if(to=='.'){
				break;
			}
		}
		//end of input processing
		//start of solving
		
		
		
		int currP = intStartP;
		int currL = intStartL;
		int nextP = moveP(intStartP);
		int nextL = moveL(intStartL);
		visitedP[intStartP]=true;
		visitedL[intStartL]=true;
		if(currP==currL){
			nextP=currP;
			nextL=currL;
		}
		else{
			nextP = moveP(intStartP);
			nextL = moveL(intStartL);
		}
		
		//cout <<currP << " " << currL << endl;
		//cout <<nextP << " " << nextL << endl;
		
		while(true){
			if((nextP==nextL)&&(nextP!=-1)){
				printf("Both annihilated in node %c\n",getChar(nextP));
				break;
			}
			else if((nextP==-1)&&(nextL==currP)){
				printf("Paskill trapped in node %c Both annihilated in node %c\n",getChar(currP),getChar(currP));
				break;
			}
			else if((nextP==-1)&&(nextL==-1)){
				printf("Paskill trapped in node %c Lisper trapped in node %c\n",getChar(currP),getChar(currL));
				break;
			}
			else if((nextP==-1)&&(visitedP[nextL])){
				printf("Paskill trapped in node %c Lisper destroyed in node %c\n",getChar(currP),getChar(nextL));
				break;
			}
			else if(nextP==-1){
				printf("Paskill trapped in node %c\n",getChar(currP));
				break;
			}
			else if(nextL==-1){
				printf("Lisper trapped in node %c\n",getChar(currL));
				break;
			}
			else if(visitedP[nextL]){
				printf("Lisper destroyed in node %c\n",getChar(nextL));
				break;
			}
			else{
				currP=nextP;
				currL=nextL;
				visitedP[currP]=true;
				visitedL[currL]=true;
				nextP = moveP(currP);
				nextL = moveL(currL);
			}
			//cout <<"A";	
		}
		
		//end of solving
		
		/*
		for(int i=0;i<27;i++){
			cout << i << endl;
			for(unsigned int j=0;j<adjList[i].size();j++){
				cout << adjList[i][j] << " ";
			}
			cout << endl;
		}*/
		
		//clearing
		for(int i=0;i<=27;i++){
			adjList[i].clear();
		}
		
		getline(cin,word);
	}
	
	return 0;
}
