//Steven Kester Yuwono - UVa 580

#include <cstdio>
using namespace std;

int memo[31];

void init(){
	memo[1] = 0;
	memo[2] = 0;
	memo[3] = 1;
	memo[4] = 3;
	memo[5] = 8;
	memo[6] = 20;
	memo[7] = 47;
	memo[8] = 107;
	memo[9] = 238;
	memo[10] = 520;
	memo[11] = 1121;
	memo[12] = 2391;
	memo[13] = 5056;
	memo[14] = 10616;
	memo[15] = 22159;
	memo[16] = 46023;
	memo[17] = 95182;
	memo[18] = 196132;
	memo[19] = 402873;
	memo[20] = 825259;
	memo[21] = 1686408;
	memo[22] = 3438828;
	memo[23] = 6999071;
	memo[24] = 14221459;
	memo[25] = 28853662;
	memo[26] = 58462800;
	memo[27] = 118315137;
	memo[28] = 239186031;
	memo[29] = 483072832;
	memo[30] = 974791728;
	return;
}

int main(){
	init();
	int n;
	while(((scanf("%d",&n))==1)&&(n!=0)){
		printf("%d\n",memo[n]);
	}
	return 0;
}