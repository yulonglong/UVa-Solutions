//Steven Kester Yuwono - UVa 11744

#include <iostream>
using namespace std;

bool process (string a, string b, string& c, string& d) {
	c = "";
	d = "";
	for(int i=0;i<(int)a.length();i++) {
		if(a[i]!=b[i]) {
			c = c + "1";
		}
		else {
			c = c + "0";	
		}
		if ((a[i] == '0') || (b[i] == '0')) {
			d = d + "0";
		}
		else {
			d = d + "1";
		}
	}
	if(d[0] == '1'){
		d = "overflow";
		return false;
	}
	d = d.substr(1);
	d = d + "0";

	for(int i=0;i<(int)d.length();i++) {
		if(d[i] != '0'){
			return true;
		}
	}
	return false;
}


int main(){
	int tc;
	cin >> tc;
	for (int z=0;z<tc;z++){
		if(z>0){
			cout  << endl;
		}
		string a,b,c,d;
		cin >> a >> b;
		bool valid = true;
		cout << a << " " << b << endl;
		while (process(a,b,c,d) ){
			a = c;
			b = d;
			cout << a << " " << b << endl;
		}
		cout << c << " " << d << endl;
	}
}