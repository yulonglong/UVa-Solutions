// Steven Kester Yuwono - UVa 11034

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int l,m; cin >> l >> m;
		l = l*100;
		queue<int> left, right;
		for(int i=0;i<m;i++){
			int len;
			string loc;
			cin >> len >> loc;
			if(loc == "left") left.push(len);
			else right.push(len);
		}

		bool atLeft = true;
		int count = 0;
		while ((!left.empty()) || (!right.empty())) {
			int currLoad = 0;
			if (atLeft) {
				while ((currLoad < l) && (!left.empty())) {
					if (currLoad + left.front() <= l) {
						currLoad += left.front();
						left.pop();
					}
					else break;
				}
				atLeft = false;
				count++;
			}
			else {
				while ((currLoad < l) && (!right.empty())) {
					if (currLoad + right.front() <= l) {
						currLoad += right.front();
						right.pop();
					}
					else break;
				}
				atLeft = true;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}