#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct wave{
    int r;
    int c;
    int cost;
    bool operator () (wave const &a, wave const &b){
        return a.cost > b.cost;
    }
};


int g[1001][1001];
int cost[1001][1001];
bool visited[1001][1001];
priority_queue<wave,vector<wave>,wave> pq;

int main(){
    int mainR,mainC;
    scanf("%d %d",&mainR,&mainC);
    //cout << mainR << " " <<  mainC << endl;
    char temp;
    for(int i=1;i<=mainR;i++){
        for(int j=1;j<=mainC;j++){
            cin >> temp;
            //cout << temp;
            g[i][j]=temp -'0';
        }
        //cout << endl;
    }
    
    int tc;
    scanf("%d",&tc);
    //cout << tc << endl;
    while(tc--){
        int rs,cs,rd,cd;
        scanf("%d %d %d %d",&rs, &cs, &rd, &cd);
        //cout << rs <<" " <<cs << " " << rd << " " <<cd << endl;
        if((rs==rd)&&(cs==cd)){
            cost[rd][cd]=0;
        }
        else{
            for(int i=0;i<1001;i++){
                memset(visited[i],false,sizeof(visited[i]));
            }
            for(int i=0;i<1001;i++){
                for(int j=0;j<1001;j++){
                    cost[i][j]=2000000000;
                }
            }
            
            wave tw;
            tw.r=rs;
            tw.c=cs;
            tw.cost=0;
            cost[rs][cs]=0;
            pq.push(tw);
            
            while(!pq.empty()){
                wave tempWave;
                tempWave = pq.top();
                pq.pop();
                int r=tempWave.r;
                int c=tempWave.c;
                //cout << r << " " << c << " " << cost[r][c] << endl;
                visited[r][c]=true;
                
                int tempCost[8];
                for(int i=0;i<8;i++){
                    tempCost[i]=1;
                }
                int index=g[r][c];
                tempCost[index]=0;
                
                if(r-1>=1){
                    if(cost[r][c]+tempCost[0]<cost[r-1][c]){
                        cost[r-1][c]=cost[r][c]+tempCost[0];
                        if(!visited[r-1][c]){
                            wave tempWave1;
                            tempWave1.r=r-1;
                            tempWave1.c=c;
                            tempWave1.cost=tempCost[0]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                }
                if((r-1>=1)&&(c+1<=mainC)){
                    if(cost[r][c]+tempCost[1]<cost[r-1][c+1]){
                        cost[r-1][c+1]=cost[r][c]+tempCost[1];
                        if(!visited[r-1][c+1]){
                            wave tempWave1;
                            tempWave1.r=r-1;
                            tempWave1.c=c+1;
                            tempWave1.cost=tempCost[1]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                }
                if(c+1<=mainC){
                    if(cost[r][c]+tempCost[2]<cost[r][c+1]){
                        cost[r][c+1]=cost[r][c]+tempCost[2];
                        if(!visited[r][c+1]){
                            wave tempWave1;
                            tempWave1.r=r;
                            tempWave1.c=c+1;
                            tempWave1.cost=tempCost[2]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                    
                }
                if((r+1<=mainR)&&(c+1<=mainC)){
                    if(cost[r][c]+tempCost[3]<cost[r+1][c+1]){
                        cost[r+1][c+1]=cost[r][c]+tempCost[3];
                        if(!visited[r+1][c+1]){
                            wave tempWave1;
                            tempWave1.r=r+1;
                            tempWave1.c=c+1;
                            tempWave1.cost=tempCost[3]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                }
                if(r+1<=mainR){
                    if(cost[r][c]+tempCost[4]<cost[r+1][c]){
                        cost[r+1][c]=cost[r][c]+tempCost[4];
                        if(!visited[r+1][c]){
                            wave tempWave1;
                            tempWave1.r=r+1;
                            tempWave1.c=c;
                            tempWave1.cost=tempCost[4]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                }
                if((r+1<=mainR)&&(c-1>=1)){
                    if(cost[r][c]+tempCost[5]<cost[r+1][c-1]){
                        cost[r+1][c-1]=cost[r][c]+tempCost[5];
                        if(!visited[r+1][c-1]){
                            wave tempWave1;
                            tempWave1.r=r+1;
                            tempWave1.c=c-1;
                            tempWave1.cost=tempCost[5]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                }
                if(c-1>=1){
                    if(cost[r][c]+tempCost[6]<cost[r][c-1]){
                        cost[r][c-1]=cost[r][c]+tempCost[6];
                        if(!visited[r][c-1]){
                            wave tempWave1;
                            tempWave1.r=r;
                            tempWave1.c=c-1;
                            tempWave1.cost=tempCost[6]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                    
                }
                if((c-1>=1)&&(r-1>=1)){
                    if(cost[r][c]+tempCost[7]<cost[r-1][c-1]){
                        cost[r-1][c-1]=cost[r][c]+tempCost[7];
                        if(!visited[r-1][c-1]){
                            wave tempWave1;
                            tempWave1.r=r-1;
                            tempWave1.c=c-1;
                            tempWave1.cost=tempCost[7]+cost[r][c];
                            pq.push(tempWave1);
                        }
                    }
                }
                
            }
            
        }
        cout << cost[rd][cd] << endl;
        
        
    }
    
    
    return 0;
}