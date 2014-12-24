//Steven Kester Yuwono - UVa 11223

#include <iostream>
#include <map>
using namespace std;

map <string, string> m;

void init(){
    m[""] = "";

    m[".-"] = "A";
    m["-..."] = "B";
    m["-.-."] = "C";
    m["-.."] = "D";
    m["."] = "E";
    m["..-."] = "F";
    m["--."] = "G";
    m["...."] = "H";
    m[".."] = "I";
    m[".---"] = "J";
    m["-.-"] = "K";
    m[".-.."] = "L";
    m["--"] = "M";
    m["-."] = "N"; 
    m["---"] = "O";
    m[".--."] = "P";
    m["--.-"] = "Q";
    m[".-."] = "R";
    m["..."] = "S";
    m["-"] = "T";
    m["..-"] = "U";
    m["...-"] = "V";
    m[".--"] = "W";
    m["-..-"] = "X";
    m["-.--"] = "Y";
    m["--.."] = "Z";

    m["-----"] = "0";
    m[".----"] = "1";
    m["..---"] = "2";
    m["...--"] = "3";
    m["....-"] = "4";
    m["....."] = "5";
    m["-...."] = "6";
    m["--..."] = "7";
    m["---.."] = "8";
    m["----."] = "9";

    m[".-.-.-"] = ".";
    m["--..--"] = ",";
    m["..--.."] = "?";
    m[".----."] = "\'";
    m["-.-.--"] = "!";
    m["-..-."] = "/";
    m["-.--."] = "(";
    m["-.--.-"] = ")";
	m[".-..."] = "&";
    m["---..."] = ":";
    m["-.-.-."] = ";";
    m["-...-"] = "=";
    m[".-.-."] = "+";
    m["-....-"] = "-";
    m["..--.-"] = "_";
    m[".-..-."] = "\"";
    m[".--.-."] = "@";
}

int main(){
    init();
	int tc;
	cin >> tc;
	string temp;
	getline(cin,temp); //dummy getline
	for(int d = 1; d <= tc; d++){
		if(d>1){
			cout << endl;
		}
		cout << "Message #" << d << endl;
		string line;
		getline(cin,line);
		string letter = "";
		for(int i=0;i<(int)line.length();i++){
			if(line[i]!=' '){
				letter = letter + line[i];
			}
			else {
                cout << m[letter];
                letter = "";
                if(i+1<(int)line.length()){
                    if (line[i+1]==' '){
                        cout << " ";
                        i++;
                    }
                }
			}
		}
		cout << m[letter] << endl;
	}
	return 0;
}

