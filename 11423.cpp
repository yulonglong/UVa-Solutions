//Steven Kester Yuwono - UVa 11423
//Fenwick Tree (Binary Indexed Tree)

#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 31
#define MAXFT 10000100
#define MAXARR 20000100
using namespace std;

int N;
int stat[MAX];
int maxSize[MAX];
int visitedCounter[MAXARR];
int counter = 0;

// BEGIN Fenwick Tree quoted from CP3

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;
public:
  FenwickTree() {}
  FenwickTree(int n) { 
  	ft.assign(n + 1, 0); 
  }
  int rsq(int b) {
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

// END Fenwick Tree quoted from CP3

FenwickTree ft(MAXFT);

void processCache(int addr){
	if(visitedCounter[addr]) {
		int max = ft.rsq(visitedCounter[addr],counter);
		int maxIndex = N;
		for(int i=0;i<N;i++){
			if(maxSize[i] >= max){
				maxIndex = i;
				break;
			}
		}
		for(int i=0;i<maxIndex;i++){
			stat[i]++;
		}
		ft.adjust(visitedCounter[addr], -1);
	}
	else {
		for(int i=0;i<N;i++){
			stat[i]++;
		}
	}
	counter++;
	visitedCounter[addr] = counter; 
	ft.adjust(visitedCounter[addr], 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> maxSize[i];
	}

	string command;
	while((cin >> command) && (command != "END")) {
		if(command == "STAT"){
			for(int i=0;i<N;i++){
				if(i!=0){
					cout << " ";
				}
				cout << stat[i];
				stat[i] = 0;
			}
			cout << endl;
		}
		else if(command == "ADDR"){
			int addr;
			cin >> addr;
			processCache(addr);
		}
		else if(command == "RANGE") {
			int b,y,n;
			cin >> b >> y >> n;
			for(int i=0;i<n;i++){
				processCache(b+y*i);
			}
		}
	}
	return 0;
}