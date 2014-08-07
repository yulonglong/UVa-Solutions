#include <bits/stdc++.h>
using namespace std;

struct wave{
    int x;
    int y;
    int cost;
    int type;
    bool operator () (wave const &a, wave const &b){
        return a.cost > b.cost;
    }
};

bool obstacle[41][41];
bool visited[41][41];
int cost[41][41];
priority_queue < wave,vector<wave>,wave > pq;


int main(){
    int n;
    cin >> n;
    while (n!=0){
        n=2*n;
        int sx, sy, ex, ey;
        cin >> sx >> sy;
        cin >> ex >> ey;
        
        //cout << sx << " " << sy << endl;
        //cout << ex << " " << ey << endl;
        
        for (int i=0;i<41;i++){
            for (int j=0;j<41;j++){
                visited[i][j]=false;
                obstacle[i][j]=false;
                cost[i][j]=2000000000;
            }
        }
        
        
        int tempx, tempy;
        cin >> tempx >> tempy;
        while(!((tempx==0)&&(tempy==0))){
            obstacle[tempx][tempy]=true;
            cin >> tempx >> tempy;
        }
        
        //start dijkstra
        
        wave newW;
        newW.x=sx;
        newW.y=sy;
        newW.cost=0;
        newW.type=0;
        cost[sx][sy]=0;
        pq.push(newW);
        
        while(!pq.empty()){
            wave temp = pq.top();
            pq.pop();
            int x=temp.x;
            int y=temp.y;
            int type=temp.type;
            //cout << x << " " << y << " " << cost[x][y] << endl;
            visited[x][y]=true;
            
            if(((x-1>=1)&&(y-2>=1))&&(!obstacle[x-1][y-2])&&(type!=1)){
                if(cost[x-1][y-2]>cost[x][y]+1){
                    cost[x-1][y-2]=cost[x][y]+1;
                    if(!visited[x-1][y-2]){
                        wave temp2;
                        temp2.x=x-1;
                        temp2.y=y-2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x-2>=1)&&(y-2>=1))&&(!obstacle[x-2][y-2])&&(type!=2)){
                if(cost[x-2][y-2]>cost[x][y]+1){
                    cost[x-2][y-2]=cost[x][y]+1;
                    if(!visited[x-2][y-2]){
                        wave temp2;
                        temp2.x=x-2;
                        temp2.y=y-2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=2;
                        pq.push(temp2);
                    }
                }
            }
            if(((x-2>=1)&&(y-1>=1))&&(!obstacle[x-2][y-1])&&(type!=1)){
                if(cost[x-2][y-1]>cost[x][y]+1){
                    cost[x-2][y-1]=cost[x][y]+1;
                    if(!visited[x-2][y-1]){
                        wave temp2;
                        temp2.x=x-2;
                        temp2.y=y-1;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x-2>=1)&&(y+1<=n))&&(!obstacle[x-2][y+1])&&(type!=1)){
                if(cost[x-2][y+1]>cost[x][y]+1){
                    cost[x-2][y+1]=cost[x][y]+1;
                    if(!visited[x-2][y+1]){
                        wave temp2;
                        temp2.x=x-2;
                        temp2.y=y+1;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x-2>=1)&&(y+2<=n))&&(!obstacle[x-2][y+2])&&(type!=2)){
                if(cost[x-2][y+2]>cost[x][y]+1){
                    cost[x-2][y+2]=cost[x][y]+1;
                    if(!visited[x-2][y+2]){
                        wave temp2;
                        temp2.x=x-2;
                        temp2.y=y+2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=2;
                        pq.push(temp2);
                    }
                }
            }
            if(((x-1>=1)&&(y+2<=n))&&(!obstacle[x-1][y+2])&&(type!=1)){
                if(cost[x-1][y+2]>cost[x][y]+1){
                    cost[x-1][y+2]=cost[x][y]+1;
                    if(!visited[x-1][y+2]){
                        wave temp2;
                        temp2.x=x-1;
                        temp2.y=y+2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x+1<=n)&&(y+2<=n))&&(!obstacle[x+1][y+2])&&(type!=1)){
                if(cost[x+1][y+2]>cost[x][y]+1){
                    cost[x+1][y+2]=cost[x][y]+1;
                    if(!visited[x+1][y+2]){
                        wave temp2;
                        temp2.x=x+1;
                        temp2.y=y+2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x+2<=n)&&(y+2<=n))&&(!obstacle[x+2][y+2])&&(type!=2)){
                if(cost[x+2][y+2]>cost[x][y]+1){
                    cost[x+2][y+2]=cost[x][y]+1;
                    if(!visited[x+2][y+2]){
                        wave temp2;
                        temp2.x=x+2;
                        temp2.y=y+2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=2;
                        pq.push(temp2);
                    }
                }
            }
            if(((x+2<=n)&&(y+1<=n))&&(!obstacle[x+2][y+1])&&(type!=1)){
                if(cost[x+2][y+1]>cost[x][y]+1){
                    cost[x+2][y+1]=cost[x][y]+1;
                    if(!visited[x+2][y+1]){
                        wave temp2;
                        temp2.x=x+2;
                        temp2.y=y+1;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x+2<=n)&&(y-1>=1))&&(!obstacle[x+2][y-1])&&(type!=1)){
                if(cost[x+2][y-1]>cost[x][y]+1){
                    cost[x+2][y-1]=cost[x][y]+1;
                    if(!visited[x+2][y-1]){
                        wave temp2;
                        temp2.x=x+2;
                        temp2.y=y-1;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            if(((x+2<=n)&&(y-2>=1))&&(!obstacle[x+2][y-2])&&(type!=2)){
                if(cost[x+2][y-2]>cost[x][y]+1){
                    cost[x+2][y-2]=cost[x][y]+1;
                    if(!visited[x+2][y-2]){
                        wave temp2;
                        temp2.x=x+2;
                        temp2.y=y-2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=2;
                        pq.push(temp2);
                    }
                }
            }
            if(((x+1<=n)&&(y-2>=1))&&(!obstacle[x+1][y-2])&&(type!=1)){
                if(cost[x+1][y-2]>cost[x][y]+1){
                    cost[x+1][y-2]=cost[x][y]+1;
                    if(!visited[x+1][y-2]){
                        wave temp2;
                        temp2.x=x+1;
                        temp2.y=y-2;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=1;
                        pq.push(temp2);
                    }
                }
            }
            int newX = abs(n-x) + 1;
            int newY = abs(n-y) + 1;
            
            if ((!obstacle[newX][y])&&(type!=3)){
                if(cost[newX][y]>cost[x][y]+1){
                    cost[newX][y]=cost[x][y]+1;
                    if(!visited[newX][y]){
                        wave temp2;
                        temp2.x=newX;
                        temp2.y=y;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=3;
                        pq.push(temp2);
                    }
                }
            }
            if ((!obstacle[x][newY])&&(type!=3)){
                if(cost[x][newY]>cost[x][y]+1){
                    cost[x][newY]=cost[x][y]+1;
                    if(!visited[x][newY]){
                        wave temp2;
                        temp2.x=x;
                        temp2.y=newY;
                        temp2.cost=cost[x][y]+1;
                        temp2.type=3;
                        pq.push(temp2);
                    }
                }
            }
        }
        
        if(cost[ex][ey]==2000000000){
            cout << "Solution doesn't exist" << endl;
        }
        else{
            cout << "Result : " << cost[ex][ey] << endl;
        }
        
        //end dijkstra
        
        cin >> n;
    }
    return 0;
}