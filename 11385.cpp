// Steven Kester Yuwono - UVa 11385

#include <iostream>
#include <map>
#include <queue>
#define MAX 101
using namespace std;

map <int,int> fibMap;
map <int,int>::iterator it;
int fib[MAX];

void init() {
	fibMap.insert(pair<int,int>(1,1));
	fibMap.insert(pair<int,int>(2,2));
	fib[1] = 1;
	fib[2] = 2;
	for(int i=3;i<MAX;i++){
		fib[i] = fib[i-1] + fib[i-2];
		fibMap.insert(pair<int,int>(fib[i],i));
	}
	return;
}

int main() {
	init();
	int tc; cin >> tc;
	while (tc--){
		int biggestFib = -1;
		int num; cin >> num;
		queue<int> fibQ;
		for(int i=0;i<num;i++){
			int temp; cin >> temp;
			fibQ.push(temp);
		}
		string tempStr; getline(cin,tempStr);
		string message; getline(cin,message);
		queue<char> messageQ;
		for(int i=0;i<(int)message.length();i++){
			if(isalpha(message[i])&&isupper(message[i])) {
				messageQ.push(message[i]);
			}
		}
		char answer[MAX];
		for(int i=0;i<MAX;i++){
			answer[i] = ' ';
		}

		while(!fibQ.empty()){
			it = fibMap.find(fibQ.front());
			int index = it->second;
			biggestFib = max(biggestFib,index);
			answer[index] = messageQ.front();
			fibQ.pop(); messageQ.pop();
		}

		for(int i=1;i<=biggestFib;i++){
			cout << answer[i];
		}
		cout << endl;
	}
	return 0;
}