// Steven Kester Yuwono - UVa 11039

#include <bits/stdc++.h>
using namespace std;

int getMaximumHeight(vector<int> posFloor, vector<int> negFloor, string currColor) {
	int count = 0;
	int posIndex = 0;
	int negIndex = 0;
	int currSize = 0;
	while (true) {
		if (currColor == "pos") {
			while (posIndex < posFloor.size() && currSize >= posFloor[posIndex]) posIndex++;
			if (posIndex < posFloor.size()) {
				count++;
				currSize = posFloor[posIndex];
				currColor = "neg";
			}
			else break;
		}
		else {
			while (negIndex < negFloor.size() && currSize >= negFloor[negIndex]) negIndex++;
			if (negIndex < negFloor.size()) {
				count++;
				currSize = negFloor[negIndex];
				currColor = "pos";
			}
			else break;
		}
	}
	return count;

}

int main() {
	int t; scanf("%d",&t);
	while (t--) {
		vector<int> posFloor;
		vector<int> negFloor;
		int n; scanf("%d",&n);
		for (int i=0; i<n; i++) {
			int curr; scanf("%d",&curr);
			if (curr > 0) posFloor.push_back(curr);
			else negFloor.push_back(-1*curr);
		}
		sort(posFloor.begin(), posFloor.end());
		sort(negFloor.begin(), negFloor.end());

		int count1 = getMaximumHeight(posFloor, negFloor, "pos");
		int count2 = getMaximumHeight(posFloor, negFloor, "neg");
		if (count1 > count2) printf("%d\n", count1);
		else printf("%d\n", count2);
	}
	return 0;
}
