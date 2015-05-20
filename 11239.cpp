// Steven Kester Yuwono - UVa 11239

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

map<string,int> project;
map<string,int>::iterator it;
int numStudents[200];
string projectName[200];

struct Node {
	string name;
	int count;
	Node() {
		name = "";
		count = 0;
	}
	Node(string newName, int newCount) {
		name = newName;
		count = newCount;
	}
	bool operator() (const Node& lhs, const Node& rhs) {
		if (lhs.count == rhs.count) {
			return lhs.name < rhs.name;
		}
		return lhs.count > rhs.count;
	}
};

int main() {
	string word;
	int projectIndex = -1;
	while(getline(cin,word)) {
		if(!isalpha(word[0])) {
			if(word == "1") {
				vector<Node>  ans;
				ans.clear();
				for(int i=0;i<=projectIndex;i++){
					ans.push_back(Node(projectName[i],numStudents[i]));
				}

				sort (ans.begin(), ans.end(), Node());
				for(int i=0;i<=projectIndex;i++){
					cout << ans[i].name << " " << ans[i].count << endl;
				}


				memset(numStudents,0,sizeof(numStudents));
				projectIndex = -1;
				project.clear();
			}
			else if(word == "0") {
				break;
			}
			continue;
		}

		if(isupper(word[0])){
			projectIndex++;
			projectName[projectIndex] = word;
		}
		else {
			// cout << projectName[projectIndex] << " " << word << endl;
			it = project.find(word);
			if(it == project.end()) {
				project.insert(pair<string,int>(word,projectIndex));
				numStudents[projectIndex]++;
			}
			else {
				if ((it->second <= 200) && (it->second != projectIndex)){
					numStudents[it->second]--;
					it->second = 300;
				}
			}
		}
	}
	return 0;
}