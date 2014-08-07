#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
struct Student {
  int id, money;
};
 
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k)&& (n!=0)) {
		
		queue<Student> q;
		
		for (int i = 1; i <= n; i++) {
			Student temp;
			temp.id=i;
			temp.money=40;
			q.push(temp);
		}
  
		while (!q.empty()) {
			for (int i = 1; i <= k; i++) {
				int remaining = i;
				while ((remaining) && (!q.empty())) {
					Student curr = q.front();
					q.pop();
					
					if (curr.money > remaining) {
						curr.money -= remaining;
						remaining = 0;
						q.push(curr);
					}
					else {
						remaining = remaining - curr.money;
						printf("%3d", curr.id);
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}
