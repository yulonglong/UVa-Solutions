// Steven Kester Yuwono - UVa 11878

#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int correct = 0;
	char ans[200], op;
	int first,second;
	while(scanf("%d%c%d=%s\n",&first, &op, &second, &ans) == 4) {
		if (ans[0] == '?') continue;
		int ansInt = atoi(ans);
		if ((op == '+') && (first+second == ansInt)) correct++;
		else if ((op == '-') && (first-second == ansInt)) correct++;
	}
	printf("%d\n",correct);
}
