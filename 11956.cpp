// Steven Kester Yuwono - UVa 11956
#include <cstdio>
#include <cstring>

char instruction[100010];
int bytes[100];

int main() {
	int tc; scanf("%d",&tc);
	for(int d=1;d<=tc;d++){
		memset(bytes,0,sizeof(bytes));
		scanf("%s\n",&instruction);
		int index = 0;

		printf("Case %d:",d);
		for(int i=0;instruction[i]!='\0';i++){
			if (instruction[i] == '.') continue;
			else if (instruction[i] == '>') {
				index = (index+1)%100;
			}
			else if (instruction[i] == '<') {
				index--;
				if (index<0) index = 99;
			}
			else if (instruction[i] == '+') bytes[index] = (bytes[index]+1) %256;
			else if (instruction[i] == '-') {
				bytes[index] = (bytes[index]-1);
				if (bytes[index] < 0) bytes[index] = 255;
			}
		}
		for(int i=0;i<100;i++){
			printf(" %.2X", bytes[i]);
		}
		printf("\n");
	}
	return 0;
}
