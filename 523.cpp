//Steven Kester Yuwono - UVa 523

#include <bits/stdc++.h>
#define MAXN 505

using namespace std;

class mycomparison{
public:
  bool operator() (const pair<int,int>& lhs, const pair<int,int> &rhs) const
  {
    return (lhs.first>rhs.first);
  }
};

int adjm[MAXN][MAXN];
int graphCost[MAXN];
int parent[MAXN];
bool visited[MAXN];
priority_queue<pair<int,int>, vector<pair <int,int> >, mycomparison> pq;
int tax[MAXN];
int n=0;

void print(){
	cout << "adj matrix" << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << adjm[i][j] << " ";
		}
		cout << endl;
	}
	cout << "tax" << endl;
	for(int i=1;i<=n;i++){
		cout << tax[i] << " ";
	}
	cout << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	
	string word;
	getline(cin,word);
	int tc;
	tc=atoi(word.c_str());
	getline(cin,word);//get the blank line;
	while(tc--){
		for(int i=0;i<MAXN;i++){
			memset(adjm[i],0,sizeof(adjm[i]));
		}
		getline(cin,word);//real word;
		istringstream instream(word);
		int tempInt;
		n=0;
		while(instream>>tempInt){
			n++;
			adjm[1][n]=tempInt;
		}
		for(int i=2;i<=n;i++){
			getline(cin,word);
			istringstream instream2(word);
			for(int j=1;j<=n;j++){
				instream2>>tempInt;
				adjm[i][j]=tempInt;
			}
		}
		
		getline(cin,word);
		istringstream instream3(word);
		for(int i=1;i<=n;i++){
			instream3>>tempInt;
			tax[i]=tempInt;
		}
		
		getline(cin,word);
		int flag=0;
		while(word.length()>0){
			if(flag){
				printf("\n");
			}
			flag=1;
			int source, dest;
			istringstream instream4(word);
			instream4 >> source >> dest;
			
			for(int i=0;i<MAXN;i++){
				graphCost[i]=2000000000;
			}
			memset(parent,0,sizeof(parent));
			memset(visited,false,sizeof(visited));
			
			pq.push(pair<int,int>(0,source));
			graphCost[source]=0;
			visited[source]=true;
			
			while(!pq.empty()){
				int vertex=pq.top().second;
				pq.pop();
				visited[vertex]=true;
				for(int i=1;i<=n;i++){
					if(adjm[vertex][i]>-1){
						if(adjm[vertex][i] + graphCost[vertex] + tax[i] < graphCost[i]){
							graphCost[i] = adjm[vertex][i] + graphCost[vertex] + tax[i] ;
							parent[i]=vertex;
							if(!visited[i]){
								pq.push(pair<int,int>(graphCost[i],i));
							}
						}
					}
				}
			}
			
			printf("From %d to %d :\n",source,dest);
			printf("Path: ");
			int ansCost=graphCost[dest]-tax[dest];
			if(source==dest){
				ansCost=0;
			}
			
			stack<int> answerSt;
			while(dest!=source){
				answerSt.push(dest);
				dest=parent[dest];
			}
			answerSt.push(source);
			if(ansCost==0){
				printf("%d-->",answerSt.top());
			}
			
			while(answerSt.size()>1){
				printf("%d-->",answerSt.top());
				answerSt.pop();
			}
			printf("%d\n",answerSt.top());
			answerSt.pop();
			
			printf("Total cost : %d\n",ansCost);
			
			getline(cin,word);
		}
		//print();
		
		if(tc){
			printf("\n");
		}
	}
	return 0;
}
