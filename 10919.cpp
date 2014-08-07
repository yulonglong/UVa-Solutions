//uva 10919
#include <bits/stdc++.h>
using namespace std;

map <string, bool> course;

int main (){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
    int k;
    while (scanf ("%d", &k)&&(k!=0)) {
		course.clear();
        int m;
        scanf ("%d", &m);
        map <string, bool> mapping;

        for (int i=0;i<k;i++) {
            string temp;
            cin >> temp;
			course[temp]=true;
        }
        int valid = true;
 
        for (int i=0;i<m;i++) {
            int n;
            scanf ("%d", &n);
            int num;
            scanf ("%d", &num);
            for ( int j=0;j<n;j++) {
                string temp;
				cin >> temp;
                if (course[temp]){
					num--;
				}
            }
            if (num>0) {
				valid = false;
			}
        }
        if (valid) {
			printf ("yes\n");
		}
        else {
			printf ("no\n");
		}
    }
    return 0;
}
