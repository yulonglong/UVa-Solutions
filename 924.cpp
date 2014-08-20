//Steven Kester Yuwono - UVa 924

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> employee[2501];
bool visited[2501];
int visitedDay[2501];
int maxBoom[500000];

void init(){
	for(int i=0;i<2501;i++){
		employee[i].clear();
	}
	return;
}

void clear( std::queue<int> &q ){
   std::queue<int> empty;
   std::swap( q, empty );
}

int main(){
	init();
	int numEmployee;
	cin >> numEmployee;
	for(int i=0;i<numEmployee;i++){
		int n;
		cin >> n;
		for(int j=0;j<n;j++){
			int temp;
			cin >> temp;
			employee[i].push_back(temp);
		}
	}
	int tc;
	cin >> tc;
	for(int d=0;d<tc;d++){
		int start;
		cin >> start;
		
		if(employee[start].size()==0){
			cout << "0" << endl;
			continue;
		}
		
		memset(visited,false,sizeof(visited));
		memset(visitedDay,0,sizeof(visitedDay));
		memset(maxBoom,0,sizeof(maxBoom));
		queue<int> q;
		clear(q);
		q.push(start);
		int day=0;
        visitedDay[start]=0;
        visited[start]=true;
		int maximumBoom=-1;
        int maximumDay=-1;
		int firstDay = -1;
		
		while(!q.empty()){
			int currVertex = q.front();
			q.pop();
			day=visitedDay[currVertex];
			maxBoom[day]++;
            
            //for debuggning purposes
            //cout << "day " << day << endl;
            //cout << "currVertex " << currVertex << endl;
            //cout << "maxBoom(" << day << ") " << maxBoom[day] << endl;
            
            if(maximumDay<day){
                maximumDay=day;
            }
			for(int i=0;i<(int)employee[currVertex].size();i++){
				if(visited[employee[currVertex][i]]==false){
					q.push(employee[currVertex][i]);
					visited[employee[currVertex][i]]=true;
					visitedDay[employee[currVertex][i]]=day+1;
				}
            }
		}
        for(int i=0;i<=maximumDay;i++){
            if(maximumBoom<maxBoom[i]){
                maximumBoom = maxBoom[i];
                firstDay = i;
            }
        }
        //if the maximum is one and occurs on the firstDay, it is regarded as day 1
        if(firstDay==0){
            firstDay = 1;
        }
		cout << maximumBoom << " " << firstDay << endl;
	
	}
	
	return 0;
}
