// Steven Kester Yuwono
// UVa 138

#include <iostream>
#include <iomanip>
using namespace std;

/* The numbers are:
6 8
35 49
204 288
1189 1681
6930 9800
40391 57121
100469 107694
1250970 1251592
2096128 2097152
24080765 24080817
*/

int main() {
	int first[10] = {6,35,204,1189,6930,40391,235416,1372105,7997214,46611179};
	int second[10] = {8,49,288,1681,9800,57121,332928,1940449,11309768,65918161};
	for(int i=0;i<10;i++){
		cout << setw(10) << first[i];
		cout << setw(10) << second[i];
		cout << endl;
	}
	return 0;
}