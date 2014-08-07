#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int temp;
    bool qbool=true;
    bool sbool=true;
    bool pqbool=true;
    priority_queue<int> *pq;
    stack<int> *s;
    queue<int> *q;
    pq = new priority_queue<int>();
    s = new stack<int>();
    q = new queue<int>();
    
    int n,x,y;
    while(scanf("%d",&n)==1){
        while(n--){
            scanf("%d %d",&x,&y);
            if(x==1){
                pq->push(y);
                q->push(y);
                s->push(y);
            }
            else{
                if(!pq->empty()){
                    temp=pq->top();
                    pq->pop();
                    if (temp!=y){
                        pqbool=false;
                    }
                }
                else{
                    pqbool=false;
                }
                if(!s->empty()){
                    temp=s->top();
                    s->pop();
                    if(temp!=y){
                        sbool=false;
                    }
                }
                else{
                    sbool=false;
                }
                if(!q->empty()){
                    temp=q->front();
                    q->pop();
                    if(temp!=y){
                        qbool=false;
                    }
                }
                else{
                    qbool=false;
                }
            }
        }
        
        if(pqbool&&!qbool&&!sbool){
            cout << "priority queue" << endl;
        }
        else if(!pqbool&&qbool&&!sbool){
            cout << "queue" << endl;
        }
        else if(!pqbool&&!qbool&&sbool){
            cout << "stack" << endl;
        }
        else if(!pqbool&&!qbool&!sbool){
            cout << "impossible" << endl;
        }
        else{
            cout << "not sure" << endl;
        }
        
        
        
        pqbool=true;
        qbool=true;
        sbool=true;
        pq = new priority_queue<int>();
        s = new stack<int>();
        q = new queue<int>();
    }
    
    
    return 0;
}