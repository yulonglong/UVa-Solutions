// Steven Kester Yuwono - UVa 1203
// Priority Queue

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int num;
	int period;
	int repeatingPeriod;
	Node(int _num, int _period, int _repeatingPeriod) {
		num = _num; period = _period; repeatingPeriod = _repeatingPeriod;
	}
	Node() {
		num = 0; period = 0; repeatingPeriod = 0;
	}
	bool operator() (const Node& lhs, const Node& rhs) {
		if (lhs.repeatingPeriod == rhs.repeatingPeriod) {
			return lhs.num > rhs.num;
		}
		return lhs.repeatingPeriod > rhs.repeatingPeriod;
	}
};

int main() {
	priority_queue<Node, vector<Node>, Node> pq;
	string temp;
	int num, period;
	while ((cin >> temp) && (temp != "#")) {
		cin >> num >> period;
		pq.push (Node(num,period,period));
	}
	int q; cin >> q;
	for(int i=0;i<q;i++){
		int num = pq.top().num;
		int period = pq.top().period;
		int repeatingPeriod = pq.top().repeatingPeriod + period;
		pq.pop();
		cout << num << endl;
		pq.push(Node(num,period,repeatingPeriod));
	}
	return 0;
}
