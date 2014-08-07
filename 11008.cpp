//Steven Kester Yuwono - UVa 11008

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct point { int x, y;     // whenever possible, work with point_i
  point() { x = y = 0; }                      // default constructor
  point(int _x, int _y) : x(_x), y(_y) {} };         // user-defined

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

const int MAXN = 30;
const int MAXD = 70000;
int memo[MAXD];
int g[MAXN][MAXN];
int n, m, d;
vector<point> trees;

void init(){
    memset(g, 0, sizeof(g));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i!=j){
                for (int k=n-1;k>=0;k--) {
                    g[i][j] = g[i][j]<<1;
                    if(collinear(trees[i],trees[j],trees[k])){
                        g[i][j] ++;
					}
                }
			}
		}
	}
}

int dp(int Uint){
    if (memo[Uint] != -1){
        return memo[Uint];
	}
    int temp = 0;
    for (int i=0;i<n;i++){
        if (Uint & (1<<i)){
            temp++;
		}
	}
    if (temp <= d){
        return memo[Uint] = 0;
	}
    if (temp == 1){
        return memo[Uint] = 1;
	}
    int ans = INT_MAX;
    for (int i=0;i<n;i++){
        if (Uint & (1<<i)){
            for (int j=i+1;j<n;j++){
                if (Uint & (1<<j)){
					int dpAns = dp(Uint & (~g[i][j])) + 1;
                    ans = min(ans, dpAns);
				}
			}
		}
	}
    return memo[Uint] = ans;
}


int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int N;
	cin >> N;
	for(int z=1;z<=N;z++){
		cin >> n;
		cin >> m;
		trees.clear();
		for(int i=0;i<n;i++){
			int x,y;
			cin >> x >> y;
			trees.push_back(point(x,y));
		}
		
        init();
        memset(memo, -1, sizeof(memo));
        d = n - m;
        int ans = dp((1<<n) - 1);
        
		if(z>1){
			cout << endl;
		}
		
		printf("Case #%d:\n",z);
		printf("%d\n",ans);
		
	}
	
  return 0;
}
