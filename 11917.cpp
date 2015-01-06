#include <iostream>
#include <map>
using namespace std;

map<string,int> sparrow;

int main(){
	int tc;
	cin >> tc;
	for (int d=1; d<=tc; d++){
		sparrow.clear();
		int n;
		cin >> n;
		for(int k=0; k<n; k++){
			string name;
			int duration;
			cin >> name >> duration;
			sparrow.insert(pair<string,int>(name,duration));
		}
		int deadline;
		string deadlineSubject;
		cin >> deadline >> deadlineSubject;

		map<string,int>::iterator it;
		it = sparrow.find(deadlineSubject);
		
		cout << "Case " << d << ": ";
		if ( (it == sparrow.end()) || (it->second > deadline + 5) ){
			cout << "Do your own homework!" << endl;
		}
		else if (it->second <= deadline){
			cout << "Yesss" << endl;
		}
		else if (it->second <= deadline + 5){
			cout << "Late" << endl;
		}
	}
	return 0;
}