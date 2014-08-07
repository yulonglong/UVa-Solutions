//Steven Kester Yuwono - UVa 10815

#include <cstdio>
#include <cctype>
#include <set>
#include <string>
using namespace std;

set<string> s;
char line[256], word[256];

int main(){
    s.clear();
    while(fgets(line, 256, stdin)){
        char *c = line, *w ;
        while(true){
            w=word;
            while(*c && !isalpha(*c)){
				c++;
			}
            if(!*c){
				break;
			}
            while(*c && isalpha(*c)){
				 *w++ = tolower(*c), c++;
			}
            *w=0;
            s.insert(string(word));
        }
    }
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        puts(it->c_str());
	}
    return 0;
}
