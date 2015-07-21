// Steven Kester Yuwono - UVa 12527

#include <cstdio>
#include <cstring>

bool isRepeated(int num) {
	bool temp[10];
	memset(temp,false,sizeof(temp));
	while (num > 0) {
		int mod = num%10;
		if (temp[mod]) return true;
		temp[mod] = true;
		num /= 10;
	}
	return false;
}

int main() {
	int lower,upper;
	while (scanf("%d %d",&lower,&upper)==2) {
		int count = 0;
		for(int i=lower;i<=upper;i++){
			if (!isRepeated(i)) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
