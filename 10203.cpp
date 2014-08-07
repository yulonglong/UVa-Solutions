//Steven Kester Yuwono - UVa 10203

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	int first=0;
	double sum=0;
	cin >> tc;
	while(tc--){
		if(first!=0){
            printf("\n");
        }
        else{
			first=1;
		}
		int a,b;
		cin >> a >> b;
		string word;
		getline(cin,word);
		getline(cin,word);
		sum=0;
		while(word.length()>0){
			int x1,y1,x2,y2;
			istringstream instream(word);
			instream >> x1 >> y1 >> x2 >> y2;
			sum+=(sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))))/1000;
			getline(cin,word);
		}
		
		sum*=2;
		sum=sum/20;
		int hr= (int)sum;
		sum=sum-hr;
		sum=sum*60;
		int mins=(int)sum;
		sum=sum-mins;
		if(sum>=0.5){
			mins++;
		}
		if(mins==60){
			hr++;
			mins=0;
		}
		printf("%d:%02d\n",hr, mins);
		
	}
}
