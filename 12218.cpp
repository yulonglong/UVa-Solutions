// Steven Kester Yuwono - UVa 12218

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#define MAX 10000001
using namespace std;

struct Node{
	int freq[10];
};

bool prime[MAX];
vector<Node> listPrime;

void convertIntToNode(int n, Node &count) {
	memset(count.freq,0,sizeof(count.freq));
	while(n>0){
		int curr = n%10;
		n = n/10;
		count.freq[curr]++;
	}
}

void convertStringToNode(string n, Node &count) {
	memset(count.freq,0,sizeof(count.freq));
	for(int i=0;i<(int)n.length();i++){
		int curr = n[i]-'0';
		count.freq[curr]++;
	}
}

void init() {
	memset(prime,true,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(int i=2;i<MAX;i++) {
		if(prime[i]) {
			for(int j=i*2;j<MAX;j+=i){
				prime[j] = false;
			}
		}
	}
	for(int i=0;i<MAX;i++) {
		if(prime[i]) {
			Node newNode;
			convertIntToNode(i,newNode);
			listPrime.push_back(newNode);
		}
	}
}

bool validComparison(Node &prime, Node& input){
	for(int i=0;i<10;i++){
		if(prime.freq[i]>input.freq[i]){
			return false;
		}
	}
	return true;
}

int main() {
	init();
	int tc; scanf("%d",&tc);
	while(tc--) {
		string n; cin >> n;
		Node newNode;
		convertStringToNode(n,newNode);
		int count = 0;
		for(int i=0;i<(int)listPrime.size();i++){
			if(validComparison(listPrime[i],newNode)){
				count++;
			}
		}
		printf("%d\n",count);
	}

	return 0;
}