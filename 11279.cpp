//Steven Kester Yuwono - UVa 11279

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double qwertydouble[1000];
double qwertysingle[1000];
double dvorak[1000];

void init(){
	memset(qwertydouble,0,sizeof(qwertydouble));
	qwertydouble['`'] = 4.472135955;
	qwertydouble['1'] = 4;
	qwertydouble['2'] = 4;
	qwertydouble['3'] = 4;
	qwertydouble['4'] = 4;
	qwertydouble['5'] = 4.472135955;
	qwertydouble['6'] = 4.472135955;
	qwertydouble['7'] = 4;
	qwertydouble['8'] = 4;
	qwertydouble['9'] = 4;
	qwertydouble['0'] = 4;
	qwertydouble['-'] = 4.472135955;
	qwertydouble['='] = 5.656854249;

	qwertydouble['~'] = 4.472135955;
	qwertydouble['!'] = 4;
	qwertydouble['@'] = 4;
	qwertydouble['#'] = 4;
	qwertydouble['$'] = 4;
	qwertydouble['%'] = 4.472135955;
	qwertydouble['^'] = 4.472135955;
	qwertydouble['&'] = 4;
	qwertydouble['*'] = 4;
	qwertydouble['('] = 4;
	qwertydouble[')'] = 4;
	qwertydouble['_'] = 4.472135955;
	qwertydouble['+'] = 5.656854249;

	qwertydouble['q'] = 2;
	qwertydouble['w'] = 2;
	qwertydouble['e'] = 2;
	qwertydouble['r'] = 2;
	qwertydouble['t'] = 2.828427125;
	qwertydouble['y'] = 2.828427125;
	qwertydouble['u'] = 2;
	qwertydouble['i'] = 2;
	qwertydouble['o'] = 2;
	qwertydouble['p'] = 2;
	qwertydouble['['] = 2.828427125;
	qwertydouble[']'] = 4.472135955;
	qwertydouble['\\'] = 6.32455532;

	qwertydouble['{'] = 2.828427125;
	qwertydouble['}'] = 4.472135955;
	qwertydouble['|'] = 6.32455532;


	qwertydouble['a'] = 0;
	qwertydouble['s'] = 0;
	qwertydouble['d'] = 0;
	qwertydouble['f'] = 0;
	qwertydouble['g'] = 2;
	qwertydouble['h'] = 2;
	qwertydouble['j'] = 0;
	qwertydouble['k'] = 0;
	qwertydouble['l'] = 0;
	qwertydouble[';'] = 0;
	qwertydouble['\''] = 2;

	qwertydouble[':'] = 0;
	qwertydouble['\"'] = 2;

	qwertydouble['z'] = 2;
	qwertydouble['x'] = 2;
	qwertydouble['c'] = 2;
	qwertydouble['v'] = 2;
	qwertydouble['b'] = 2.828427125;
	qwertydouble['n'] = 2.828427125;
	qwertydouble['m'] = 2;
	qwertydouble[','] = 2;
	qwertydouble['.'] = 2;
	qwertydouble['/'] = 2;

	qwertydouble['<'] = 2;
	qwertydouble['>'] = 2;
	qwertydouble['?'] = 2;
}

void init2(){
	memset(qwertysingle,0,sizeof(qwertysingle));
	qwertysingle['`'] = 8.94427191;
	qwertysingle['1'] = 7.211102551;
	qwertysingle['2'] = 5.656854249;
	qwertysingle['3'] = 4.472135955;
	qwertysingle['4'] = 4;
	qwertysingle['5'] = 4;
	qwertysingle['6'] = 4;
	qwertysingle['7'] = 4;
	qwertysingle['8'] = 4.472135955;
	qwertysingle['9'] = 5.656854249;
	qwertysingle['0'] = 7.211102551;
	qwertysingle['-'] = 8.94427191;
	qwertysingle['='] = 10.77032961;

	qwertysingle['~'] = 8.94427191;
	qwertysingle['!'] = 7.211102551;
	qwertysingle['@'] = 5.656854249;
	qwertysingle['#'] = 4.472135955;
	qwertysingle['$'] = 4;
	qwertysingle['%'] = 4;
	qwertysingle['^'] = 4;
	qwertysingle['&'] = 4;
	qwertysingle['*'] = 4.472135955;
	qwertysingle['('] = 5.656854249;
	qwertysingle[')'] = 7.211102551;
	qwertysingle['_'] = 8.94427191;
	qwertysingle['+'] = 10.77032961;

	qwertysingle['q'] = 6.32455532;
	qwertysingle['w'] = 4.472135955;
	qwertysingle['e'] = 2.828427125;
	qwertysingle['r'] = 2;
	qwertysingle['t'] = 2;
	qwertysingle['y'] = 2;
	qwertysingle['u'] = 2;
	qwertysingle['i'] = 2.828427125;
	qwertysingle['o'] = 4.472135955;
	qwertysingle['p'] = 6.32455532;
	qwertysingle['['] = 8.246211251;
	qwertysingle[']'] = 10.19803903;
	qwertysingle['\\'] = 12.16552506;

	qwertysingle['{'] = 8.246211251;
	qwertysingle['}'] = 10.19803903;
	qwertysingle['|'] = 12.16552506;

	qwertysingle['a'] = 6;
	qwertysingle['s'] = 4;
	qwertysingle['d'] = 2;
	qwertysingle['f'] = 0;
	qwertysingle['g'] = 0;
	qwertysingle['h'] = 0;
	qwertysingle['j'] = 0;
	qwertysingle['k'] = 2;
	qwertysingle['l'] = 4;
	qwertysingle[';'] = 6;
	qwertysingle['\''] = 8;

	qwertysingle[':'] = 6;
	qwertysingle['\"'] = 8;

	qwertysingle['z'] = 6.32455532;
	qwertysingle['x'] = 4.472135955;
	qwertysingle['c'] = 2.828427125;
	qwertysingle['v'] = 2;
	qwertysingle['b'] = 2;
	qwertysingle['n'] = 2;
	qwertysingle['m'] = 2;
	qwertysingle[','] = 2.828427125;
	qwertysingle['.'] = 4.472135955;
	qwertysingle['/'] = 6.32455532;

	qwertysingle['<'] = 2.828427125;
	qwertysingle['>'] = 4.472135955;
	qwertysingle['?'] = 6.32455532;
}

void init3(){
	memset(dvorak,0,sizeof(dvorak));
	dvorak['`'] = 10.77032961;
	dvorak['1'] = 8.94427191;
	dvorak['2'] = 7.211102551;
	dvorak['3'] = 5.656854249;
	dvorak['q'] = 4.472135955;
	dvorak['j'] = 4;
	dvorak['l'] = 4;
	dvorak['m'] = 4;
	dvorak['f'] = 4;
	dvorak['p'] = 4.472135955;
	dvorak['/'] = 5.656854249;
	dvorak['['] = 7.211102551;
	dvorak[']'] = 8.94427191;

	dvorak['~'] = 10.77032961;
	dvorak['!'] = 8.94427191;
	dvorak['@'] = 7.211102551;
	dvorak['#'] = 5.656854249;
	dvorak['?'] = 5.656854249;
	dvorak['{'] = 7.211102551;
	dvorak['}'] = 8.94427191;
	

	dvorak['4'] = 8.246211251;
	dvorak['5'] = 6.32455532;
	dvorak['6'] = 4.472135955;
	dvorak['.'] = 2.828427125;
	dvorak['o'] = 2;
	dvorak['r'] = 2;
	dvorak['s'] = 2;
	dvorak['u'] = 2;
	dvorak['y'] = 2.828427125;
	dvorak['b'] = 4.472135955;
	dvorak[';'] = 6.32455532;
	dvorak['='] = 8.246211251;
	dvorak['\\'] = 10.19803903;

	dvorak['$'] = 8.246211251;
	dvorak['%'] = 6.32455532;
	dvorak['^'] = 4.472135955;
	dvorak['>'] = 2.828427125;
	dvorak[':'] = 6.32455532;
	dvorak['+'] = 8.246211251;
	dvorak['|'] = 10.19803903;

	dvorak['7'] = 8;
	dvorak['8'] = 6;
	dvorak['9'] = 4;
	dvorak['a'] = 2;
	dvorak['e'] = 0;
	dvorak['h'] = 0;
	dvorak['t'] = 0;
	dvorak['d'] = 0;
	dvorak['c'] = 2;
	dvorak['k'] = 4;
	dvorak['-'] = 6;

	dvorak['&'] = 8;
	dvorak['*'] = 6;
	dvorak['('] = 4;
	dvorak['_'] = 6;

	dvorak['0'] = 8.246211251;
	dvorak['z'] = 6.32455532;
	dvorak['x'] = 4.472135955;
	dvorak[','] = 2.828427125;
	dvorak['i'] = 2;
	dvorak['n'] = 2;
	dvorak['w'] = 2;
	dvorak['v'] = 2;
	dvorak['g'] = 2.828427125;
	dvorak['\''] = 4.472135955;

	dvorak[')'] = 8.246211251;
	dvorak['<'] = 2.828427125;
	dvorak['\"'] = 4.472135955;
}


void getDistance(string line, double& scoreQwertyDouble, double& scoreQwertySingle, double& scoreDvorak){
	for(int i=0;i<(int)line.length();i++){
		if(line[i] == ' ') {
			continue;
		}
		scoreQwertyDouble += qwertydouble[tolower(line[i])];
		scoreQwertySingle += qwertysingle[tolower(line[i])];
		scoreDvorak += dvorak[tolower(line[i])];
	}
}

int main(){
	init();
	init2();
	init3();
	string line;
	while(getline(cin,line)){
		double scoreQwertySingle = 0;
		double scoreQwertyDouble = 0;
		double scoreDvorak = 0;
		getDistance(line,scoreQwertyDouble,scoreQwertySingle,scoreDvorak);
		printf("%.2f %.2f %.2f\n",scoreQwertyDouble,scoreQwertySingle,scoreDvorak);
	}
	return 0;
}