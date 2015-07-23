// Steven Kester Yuwono - UVa 12290

#include <cstdio>

bool isSeven(int num) {
	if (num%7 == 0) return true;
	while (num>0) {
		if (num%10 == 7) return true;
		num /= 10;
	}
	return false;
}

int main() {
	int n,m,k;
	while ((scanf("%d %d %d", &n, &m, &k)==3) && (n||m||k)) {
		int currK = 0;
		int currPerson = 1;
		int currNum = 1;
		bool up = true;
		while (currK < k) {
			if (isSeven(currNum) && (currPerson == m)){
				currK++;
				if (currK == k) break;
			}
			if (up && currPerson == n) up = false;
			if (!up && currPerson == 1) up = true;
			if (up) {
				currPerson++;
				currNum++;
			}
			else {
				currPerson--;
				currNum++;
			}
		}
		printf("%d\n",currNum);
	}
	return 0;
}
