//uva 11053
#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> ullull;

ull caseNo = 1, N,a,b;
ull f(ull x) { return (((((a*x)%N)*x)%N)+b)%N; }

//using floydCycle algorithm form Competitive Programming 3 book
ullull floydCycleFinding(ull x0) { // function "int f(int x)" must be defined earlier
  // 1st part: finding v, hare's speed is 2x tortoise's
  int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the element/node next to x0
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  // 2nd part: finding mu, hare and tortoise move at the same speed
  ull mu = 0; hare = x0;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
  // 3rd part: finding lambda, hare moves, tortoise stays
  int lambda = 1; hare = f(tortoise);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return ullull(mu, lambda);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	while (cin >> N >> a >> b) {
		ullull result = floydCycleFinding(0);
		//cout << result.first <<" "<< result.second << endl;
		cout <<N-result.second << endl;
	}
  return 0;
}
