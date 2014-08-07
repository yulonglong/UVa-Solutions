//Steven Kester Yuwono - UVa 10986

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct{
    int x;
    int y;
    int w;
    int l;
}edge;

class comparison{
public:
    bool operator()(edge e1,edge e2){
        if (e1.l>e2.l){
            return true;
        }
        return false;
    }
};

int main(){
    edge tempEdge;
    priority_queue<edge,vector<edge>,comparison> pq;
    queue<edge> q;
    bool visited[20001];
    bool enqueued[20001];
    int length[20001];
    for(int i=0;i<20001;i++){
		visited[i]=false;
		enqueued[i]=false;
        length[i]=99999;
    }
    int currVertex;
    int v1,v2,latency;
    int m,n,S,T;
    int tc;
    scanf("%d",&tc);
    for(int d=1;d<=tc;d++){
        scanf("%d %d %d %d",&n,&m,&S,&T);
        visited[S]=true;
        enqueued[S]=true;
        length[S]=0;
        currVertex=S;
        for (int i=1;i<=m;i++){
            scanf("%d %d %d",&v1,&v2,&latency);
            tempEdge.x=v1;
            tempEdge.y=v2;
            tempEdge.w=latency;
			tempEdge.l=latency;
            if(v1==S){
                length[v2]=latency;
                pq.push(tempEdge);
				enqueued[v2]=true;;
            }
            else if(v2==S){
                length[v1]=latency;
                pq.push(tempEdge);
                enqueued[v1]=true;;
            }
            else{
                q.push(tempEdge);
            }
        }
        
        while(!pq.empty()){
			
            tempEdge=pq.top();
            pq.pop();
            if(!visited[tempEdge.x]){
				currVertex=tempEdge.x;
				visited[currVertex]=true;;
			}
			else if(!visited[tempEdge.y]){
				currVertex=tempEdge.y;
				visited[currVertex]=true;;
			}
			else{
				continue;
			}
			
            if(currVertex==tempEdge.x){
                currVertex=tempEdge.x;
                v1=tempEdge.x;
                v2=tempEdge.y;
            }
            else{
                currVertex=tempEdge.y;
                v1=tempEdge.y;
                v2=tempEdge.x;
            }
            int qsize=q.size();
            
            for(int i=0;i<qsize;i++){
				tempEdge=q.front();
				q.pop();
				
				if(currVertex==tempEdge.x){
					if((tempEdge.w+length[currVertex])<length[tempEdge.y]){
						length[tempEdge.y]=tempEdge.w+length[currVertex];
						tempEdge.l=tempEdge.w+length[currVertex];
						if(enqueued[tempEdge.y]){
							pq.push(tempEdge);
						}
					}
					if(!enqueued[tempEdge.y]){
						pq.push(tempEdge);
						enqueued[tempEdge.y]=true;
					}
				}	
				else if(currVertex==tempEdge.y){
					if((tempEdge.w+length[currVertex])<length[tempEdge.x]){
						length[tempEdge.x]=tempEdge.w+length[currVertex];
						tempEdge.l=tempEdge.w+length[currVertex];
						if(enqueued[tempEdge.x]){
							pq.push(tempEdge);
						}
					}
					if(!enqueued[tempEdge.x]){
						pq.push(tempEdge);
						enqueued[tempEdge.x]=true;
					}
				}
				else{
					q.push(tempEdge);
				}
			}
        }
        
		printf("Case #%d: ",d);
		if(length[T]==99999){
			printf("unreachable\n");
		}
		else{
			printf("%d\n",length[T]);
		}
		
		for(int i=0;i<20001;i++){
			visited[i]=false;
			enqueued[i]=false;
			length[i]=99999;
		}
	}
    return 0;
}
