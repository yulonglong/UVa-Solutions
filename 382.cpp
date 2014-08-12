//Steven Kester Yuwono - UVa 382

#include <cstdio>
using namespace std;

int main() {
	int n;
	int total;
	bool valid;
    
	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &n) && (n)) {
        valid= false;
		total = 0;
		for (int i=1;i<n;i++) {
			if (n%i == 0)
				total = total + i;
			if (total > n) {
				valid = true;
				break;
			}
		}
        
		printf("%5d  ", n);
		if (valid){
			printf("ABUNDANT\n");
        }
		else if (total == n){
			printf("PERFECT\n");
        }
		else {
			printf("DEFICIENT\n");
        }
	}
	printf("END OF OUTPUT\n");
    
	return 0;
}