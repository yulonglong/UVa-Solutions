//uva 760

#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<ii> store;

#define MAX_N 10001                         // second approach: O(n log n)
char T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
// and current suffix T+SA[i]

bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }      // compare

void countingSort(int k) {                                          // O(n)
	int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
	memset(c, 0, sizeof c);                          // clear frequency table
	for (i = 0; i < n; i++)       // count the frequency of each integer rank
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)                     // update the suffix array SA
		SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
	for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
	for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
		countingSort(k);  // actually radix sort: sort based on the second item
		countingSort(0);          // then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
		for (i = 1; i < n; i++)                    // compare adjacent suffixes
			tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
			(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for (i = 0; i < n; i++)                     // update the rank array RA
			RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
	} }

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;                                         // default value
	for (i = 1; i < n; i++)                            // compute Phi in O(n)
		Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
	for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
		while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
		PLCP[i] = L;
		L = max(L-1, 0);                             // L decreased max n times
	}
	for (i = 0; i < n; i++)                            // compute LCP in O(n)
		LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}


int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

ii LCS() {                 // returns a pair (the LCS length and its index)
	int i, idx = 0, maxLCP = -1;
	for (i = 1; i < n; i++)                         // O(n), start from i = 1
		if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP){
			maxLCP = LCP[i], idx = i;
			
		}
	return ii(maxLCP, idx);
}

void LCS2(int lengthStr) {                 // returns a pair (the LCS length and its index)
	int i, idx = 0, maxLCP = -1;
	for (i = 1; i < n; i++)   {                      // O(n), start from i = 1
		if (owner(SA[i]) != owner(SA[i-1]) && (LCP[i] == lengthStr)){
			maxLCP = LCP[i], idx = i;
			store.push_back(ii(maxLCP,idx));
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string firstStr,secondStr,blank;
	int first=1;
	while(getline(cin,firstStr)){ 
		getline(cin,secondStr);
		getline(cin,blank);
		memset(T,0,sizeof(T));
		memset(P,0,sizeof(P));
		store.clear();
		
		strcpy(T, firstStr.c_str());
		//cout << "T" << T<< endl;
		n = (int)strlen(T);
		T[n++] = '$';

		strcpy(P, secondStr.c_str());
		//cout << "P" << P<< endl;
		m = (int)strlen(P);
		strcat(T, P);                                             
		strcat(T, "#");                                   
		n = (int)strlen(T);                                           

		// reconstruct SA of the combined strings
		constructSA();                                              // O(n log n)
		computeLCP();     

		ii ans = LCS();         // find the longest common substring between T and P
		int lengthAns = ans.first;
		
		//producing spaces
		if(first){
			first=0;
		}
		else{
			cout << endl;
		}
		//check if no common sequence
		if(lengthAns == 0){
			cout << "No common sequence." << endl;
			continue;
		}
		
		//get all the sequences with max length
		LCS2(lengthAns);
		
		string prev;
		for(int i=0;i<(int)store.size();i++){
			char lcsans[MAX_N];
			memset(lcsans,0,sizeof(lcsans));
			strncpy(lcsans, T + SA[store[i].second], store[i].first);
			string result = lcsans;
			if(prev!=result){
				cout << result << endl;
				prev=result;
			}
			//printf("The LCS is '%s' with length = %d\n", lcsans, ans.first);
		}
		
	}
	return 0;
}
