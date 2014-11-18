//Steven Kester Yuwono - UVa 837

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	double x;
	int index;
	bool operator() (const point& lhs, const point& rhs){
		return lhs.x < rhs.x;
	}
};

struct trans {
	bool on;
	double w;
};

int main(){
	int tc;
	cin >> tc;
	for(int d=0;d<tc;d++){
		int nl;
		cin >> nl;

		int np = nl * 2;
		vector<point> p(np);
		vector<trans> t(nl);
		
		for (int i=0;i<nl;i++){
			double x1,y1,x2,y2,w;
			cin >> x1 >> y1 >> x2 >> y2 >> w;
			p[i*2].x = x1;
			p[i*2].index = i;
			p[i*2+1].x = x2;
			p[i*2+1].index = i;
			t[i].w = w;
			t[i].on = false;
		}
		sort(p.begin(),p.end(),point());

		printf("%d\n",np+1);

		for(int i=0;i<=np;i++){
			if(i==0){
				printf("-inf ");
			}
			else{
				printf("%.3f ",p[i-1].x);
			}
			if(i==np){
				printf("+inf ");
			}
			else{
				printf("%.3f ",p[i].x);
			}

			double coefficient = 1.0;
			if((i>0)&&(i<np)){
				for (int j=0;j<nl;j++){
					if(t[j].on){
						coefficient = coefficient * t[j].w;
					}
				}
			}
			printf("%.3f\n",coefficient);
			if (i!=np){
				t[p[i].index].on = !t[p[i].index].on;
			}
		}
		if(d!=tc-1){
			printf("\n");
		}
	}
}