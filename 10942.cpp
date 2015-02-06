//Steven Kester Yuwono - UVa 10942

#include <cstdio>
using namespace std;

bool isLeapYear(int year){
	if (year%400 == 0)
		return true;
	else if (year%100 == 0)
		return false;
	else if (year%4 == 0 )
		return true;
	else
		return false;
}

bool isValidDate(int date[3]){
	if ((date[1]<1)||(date[1]>12)) {
		return false;
	}
	int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear(date[2])) {
    	daysInMonths[2] = 29;
    }

    if ((date[0]<1)||(date[0]>daysInMonths[date[1]])){
    	return false;
    }
    return true;
}

int chooseDate(int possibleDate[7][3]){
	bool valid[7];
	long long min = 40000000000;
	int index = -1;
	for(int i=1;i<7;i++){
		valid[i] = isValidDate(possibleDate[i]);
		if(valid[i]){
			long long value = possibleDate[i][2]*10000 + possibleDate[i][1]*50 + possibleDate[i][0];
			if(min>value){
				min = value;
				index = i;
			}
		}
	}
	return index;
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int century,x,y,z;
		scanf("%d %d %d %d",&century,&x,&y,&z);
		century = century%4;

		int possibleDate[7][3];

		// store in d,m,y manner
		possibleDate[1][0] = x;
		possibleDate[1][1] = y;
		possibleDate[1][2] = century*100 + z;

		possibleDate[2][0] = y;
		possibleDate[2][1] = x;
		possibleDate[2][2] = century*100 + z;

		possibleDate[3][0] = x;
		possibleDate[3][1] = z;
		possibleDate[3][2] = century*100 + y;

		possibleDate[4][0] = z;
		possibleDate[4][1] = x;
		possibleDate[4][2] = century*100 + y;

		possibleDate[5][0] = y;
		possibleDate[5][1] = z;
		possibleDate[5][2] = century*100 + x;

		possibleDate[6][0] = z;
		possibleDate[6][1] = y;
		possibleDate[6][2] = century*100 + x;

		int result = chooseDate(possibleDate);
		if(result == -1){
			printf("-1\n");
		}
		else {
			printf("%.2d %.2d %.2d\n",possibleDate[result][2]%100,possibleDate[result][1],possibleDate[result][0]);
		}
	}
	return 0;
}