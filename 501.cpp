#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int M, N, num[30100];
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
      cin >> num[i];
    }
    
    int done = 0;
    int need = 0;
    vector<int> box;
  
    while (N--) {
      unsigned int i;
	  cin >> i;
      while (box.size()<i) {
        vector<int>::iterator it = lower_bound(box.begin(), box.end(), num[done]);
        box.insert(it, num[done++]);
      }
      cout << box[need++] << endl;
    }
    if (tc) {
      puts("");
    }
  }
  return 0;
}
