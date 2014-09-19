//Steven Kester Yuwono - UVa 540

#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int,int> group;
map<int,int>::iterator it;
vector <pair<int,int> > q;

int main(){
	int tc;
	int d=1;
	while ((cin >> tc)&&(tc!=0)){
		group.clear();
		q.clear();
		cout << "Scenario #" << d++ << endl;
		for(int i=0;i<tc;i++){
			int n;
			cin >> n;
			for(int j=0;j<n;j++){
				int id;
				cin >> id;
				group.insert(pair<int,int>(id,i));
			}
		}
		string command;
		while ((cin>>command)&&(command!="STOP")){
			if(command=="ENQUEUE"){
				int id;
				cin >> id;
				int team;
				it = group.find(id);
				team = it->second;
				
				bool inserted = false;
				for(int i=(int)q.size()-1;i>=0;i--){
					if(q[i].second==team){
						q.insert(q.begin()+i+1,pair<int,int>(id,team));	
						inserted = true;
						break;
					}
				}
				if (!inserted){
					q.push_back(pair<int,int>(id,team));
				}

			}
			else if(command=="DEQUEUE"){
				cout << q[0].first << endl;
				q.erase(q.begin());
			}
		}
		cout << endl;
	}
	return 0;
}
