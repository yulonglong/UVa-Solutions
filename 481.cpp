//Steven Kester Yuwono - UVa 481
//Longest Increasing Subsequence (LIS)

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define MAX 100000

int lisTable[MAX];

void print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  while(p[x] >= 0){
    s.push(a[x]);
    x = p[x];
  }
  cout << a[x] << endl;
  while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
  }
}

int main() {
  int size=0;
  int temp;
  while(cin>>temp){
    lisTable[size]=temp;
    size++;
  }

  int L[MAX], L_id[MAX];
  int P[MAX];

  int lisTotal = 0;
  int lis_end = 0;
  for (int i = 0; i < size; ++i) {
    int pos = lower_bound(L, L + lisTotal, lisTable[i]) - L;
    L[pos] = lisTable[i];
    L_id[pos] = i;
    if(pos){
       P[i] = L_id[pos - 1];
    }
    else{
      P[i] = -1;
    } 

    if (pos + 1 > lisTotal) {
      lisTotal = pos + 1;
      lis_end = i;
    }

  }

  cout << lisTotal << endl;
  cout << "-" << endl;
  print(lis_end, lisTable, P);
  return 0;
}
