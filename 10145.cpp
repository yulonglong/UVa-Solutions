//Steven Kester Yuwono - UVa 10145

#include <cstdio>
#include <map>
#include <set>
using namespace std;

set<int> blocked; // transaction ID
map<int,int> lockedX; //  item ID , transaction ID
map<int,set<int> > lockedS; // itemID, list of transactionID
map<int,set<int> >::iterator itS; //iterator for lockedS
set<int>::iterator itB; //iterator Blocked
map<int,int>::iterator itX; //iterator for lockedX

char buffer[10000000];

int main() {
	gets(buffer);
	int tc;
	sscanf(buffer,"%d",&tc);
	for(int d=0;d<tc;d++){
		blocked.clear();
		lockedX.clear();
		lockedS.clear();

		if(d!=0){
			printf("\n");
		}
		
		while (gets(buffer)&&(buffer[0]!='#')){
			if(buffer[0] =='\0'){
				continue;
			}

			int trans,item;
			char cmd = buffer[0];
			sscanf(buffer+2,"%d %d",&trans,&item);

			// printf("%c %d %d\n",cmd,trans,item);
			itB = blocked.find(trans);
			if(itB != blocked.end()){
				printf("IGNORED\n");
				continue;
			}

			if(cmd == 'S'){
				// check whether item is found in lock X
				itX = lockedX.find(item);
				// if not found, granted
				if(itX == lockedX.end()) {
					itS = lockedS.find(item);
					if(itS == lockedS.end()){
						set<int> tempSet;
						tempSet.insert(trans);
						lockedS.insert(pair<int,set<int> >(item,tempSet));
					}
					else {
						(itS->second).insert(trans);
					}
					printf("GRANTED\n");
				}
				//if found, depends
				else {
					if(itX->second != trans){
						blocked.insert(trans);
						printf("DENIED\n");
					}
					else {
						printf("GRANTED\n");
					}
				}
			}
			else if(cmd == 'X'){
				int grantedFlag = true;

				// check whether itemID is found in X lock
				itX = lockedX.find(item);
				if(itX != lockedX.end()){
					if(itX ->second != trans){
						blocked.insert(trans);
						printf("DENIED\n");
						grantedFlag = false;
						continue;
					}
				}

				// check whether itemID is found in S lock
				itS = lockedS.find(item);
				if(itS != lockedS.end()) {
					set<int>::iterator it;
					for(it = itS->second.begin();it!=itS->second.end();it++){
						if(*it != trans){
							blocked.insert(trans);
							printf("DENIED\n");
							grantedFlag = false;
							break;
						}
					}
				}
				if(grantedFlag){
					lockedX.insert(pair<int,int>(item, trans));
					printf("GRANTED\n");
				}
			}
		}
	}
}
