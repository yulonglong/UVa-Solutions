// Steven Kester Yuwono - UVa 10931

#include <cstdio>
#define MAX 33

unsigned int activeBits;
char result[MAX];

void convertBits (unsigned int theNumber) {
	char tempResult[MAX];
	int index = 0;
	activeBits = 0;
	unsigned int ONE = 1;
	while (theNumber) {
		if (theNumber & 1) {
			activeBits++;
			tempResult[index++] = '1';
		}
		else tempResult[index++] = '0';
		theNumber = theNumber >> 1;
	}
	for(int i=index-1;i>=0;i--){
		result[index-1-i] = tempResult[i];
	}
	result[index] = '\0';
}

int main() {
	unsigned int input;
	while ((scanf("%d",&input)==1) && input ) {
		convertBits(input);
		printf("The parity of %s is %d (mod 2).\n", result, activeBits);
	}
	return 0;
}
