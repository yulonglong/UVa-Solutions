//Steven Kester Yuwono - UVa 929

#include <iostream>
#include <queue>
#include <vector>
#define MAX 1050
#define INF 9999999
using namespace std;


int board[MAX][MAX];
bool visited[MAX][MAX];
int cost[MAX][MAX];

struct node{
    int cost;
    int x;
    int y;
    //comparator to prioritize smaller cost
    bool operator()(const node& lhs, const node& rhs){
        return lhs.cost > rhs.cost;
    }
};

void resetCost(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cost[i][j]=INF;
        }
    }
}

void resetBoard(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            board[i][j]=0;
        }
    }
}


void resetVisited(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            visited[i][j]=false;
        }
    }
}

void resetPq(  priority_queue<node,vector<node>, node> &q ){
   priority_queue<node,vector<node>, node> empty;
   swap( q, empty );
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        resetBoard();
        resetVisited();
        resetCost();
        int maxX,maxY;
        cin >> maxX;
        cin >> maxY;
        
        for(int i=0;i<maxX;i++){
            for(int j=0;j<maxY;j++){
                cin >> board[i][j];
            }
        }
        
        priority_queue<node,vector<node>, node> pq;
		resetPq(pq);
		
        visited[0][0]=false;
        node tempNode;
        tempNode.x=0;
        tempNode.y=0;
        tempNode.cost=board[0][0];
        cost[0][0]=board[0][0];
        
        pq.push(tempNode);
        
        while(!pq.empty()){
            node currNode = pq.top();
            int x=currNode.x;
            int y=currNode.y;
			int currCost = currNode.cost;
            pq.pop();
      
			if(cost[x][y]<currCost){
				continue;
			}
			
            //go up
            if(x-1>=0){
                if(cost[x-1][y]>cost[x][y]+board[x-1][y]){
                    cost[x-1][y]=cost[x][y]+board[x-1][y];
                    node upNode;
					upNode.x=x-1;
					upNode.y=y;
					upNode.cost=currCost+board[x-1][y];
					pq.push(upNode);
                }
                
            }
            //go down
            if(x+1<=maxX-1){
                if(cost[x+1][y]>cost[x][y]+board[x+1][y]){
                    cost[x+1][y]=cost[x][y]+board[x+1][y];
                    node downNode;
					downNode.x=x+1;
					downNode.y=y;
					downNode.cost=currCost+board[x+1][y];
					pq.push(downNode);
                } 
            }
            //go left
            if(y-1>=0){
                if(cost[x][y-1]>cost[x][y]+board[x][y-1]){
                    cost[x][y-1]=cost[x][y]+board[x][y-1];
                    node leftNode;
					leftNode.x=x;
					leftNode.y=y-1;
					leftNode.cost=currCost+board[x][y-1];
					pq.push(leftNode);
                }
            }
            //go right
            if(y+1<=maxY-1){
                if(cost[x][y+1]>cost[x][y]+board[x][y+1]){
                    cost[x][y+1]=cost[x][y]+board[x][y+1];
                    node rightNode;
					rightNode.x=x;
					rightNode.y=y+1;
					rightNode.cost=currCost+board[x][y+1];
					pq.push(rightNode);
                }
            }
        }
		//cout answer
        cout << cost[maxX-1][maxY-1] << endl;   
    }
    return 0;
}
