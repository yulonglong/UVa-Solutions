//Steven Kester Yuwono - UVa 1061 - Consanguine Calculations

#include <iostream>
using namespace std;

int getAnswer(bool A[], bool B[], bool O[], bool minus,string ans[]){
	int size=0;
	if((A[0]&&O[1])||(O[0]&&A[1])||(A[0]&&A[1])){
		if(minus){
			ans[size++]="A-";
		}
		else{
			ans[size++]="A+";
			ans[size++]="A-";
		}
	}
	if((A[0]&&B[1])||(B[0]&&A[1])){
		if(minus){
			ans[size++]="AB-";
		}
		else{
			ans[size++]="AB+";
			ans[size++]="AB-";
		}
	}
	if((B[0]&&O[1])||(O[0]&&B[1])||(B[0]&&B[1])){
		if(minus){
			ans[size++]="B-";
		}
		else{
			ans[size++]="B+";
			ans[size++]="B-";
		}
	}
	if(O[0]&&O[1]){
		if(minus){
			ans[size++]="O-";
		}
		else{
			ans[size++]="O+";
			ans[size++]="O-";
		}
	}
	return size;
}

int getAnswer2(string parents, string child, bool minus,string ans[]){
	int size=0;
	if(child=="A"){
		if((parents=="A")||(parents=="AB")){
			if(minus){
				ans[size++]="A+";
				ans[size++]="AB+";
				ans[size++]="B+";
				ans[size++]="O+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="AB+";
				ans[size++]="AB-";
				ans[size++]="B+";
				ans[size++]="B-";
				ans[size++]="O+";
				ans[size++]="O-";
			}
		}
		else if(parents=="B"){
			if(minus){
				ans[size++]="A+";
				ans[size++]="AB+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="AB+";
				ans[size++]="AB-";
			}
		}
		else if(parents=="O"){
			if(minus){
				ans[size++]="A+";
				ans[size++]="AB+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="AB+";
				ans[size++]="AB-";
			}
		}
	}
	else if(child=="B"){
		if((parents=="B")||(parents=="AB")){
			if(minus){
				ans[size++]="A+";
				ans[size++]="AB+";
				ans[size++]="B+";
				ans[size++]="O+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="AB+";
				ans[size++]="AB-";
				ans[size++]="B+";
				ans[size++]="B-";
				ans[size++]="O+";
				ans[size++]="O-";
			}
		}
		else if(parents=="A"){
			if(minus){
				ans[size++]="AB+";
				ans[size++]="B+";
			}
			else{
				ans[size++]="AB+";
				ans[size++]="AB-";
				ans[size++]="B+";
				ans[size++]="B-";
			}
		}
		else if(parents=="O"){
			if(minus){
				ans[size++]="AB+";
				ans[size++]="B+";
			}
			else{
				ans[size++]="AB+";
				ans[size++]="AB-";
				ans[size++]="B+";
				ans[size++]="B-";
			}
		}
	}
	else if(child=="AB"){
		if(parents=="B"){
			if(minus){
				ans[size++]="A+";
				ans[size++]="AB+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="AB+";
				ans[size++]="AB-";
			}
		}
		else if (parents=="A"){
			if(minus){
				ans[size++]="AB+";
				ans[size++]="B+";
			}
			else{
				ans[size++]="AB+";
				ans[size++]="AB-";
				ans[size++]="B+";
				ans[size++]="B-";
			}
		}
		else if(parents=="AB"){
			if(minus){
				ans[size++]="A+";
				ans[size++]="AB+";
				ans[size++]="B+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="AB+";
				ans[size++]="AB-";
				ans[size++]="B+";
				ans[size++]="B-";
			}
		}
	}
	else if(child=="O"){
		if((parents=="O")||(parents=="A")||(parents=="B")){
			if(minus){
				ans[size++]="A+";
				ans[size++]="B+";
				ans[size++]="O+";
			}
			else{
				ans[size++]="A+";
				ans[size++]="A-";
				ans[size++]="B+";
				ans[size++]="B-";
				ans[size++]="O+";
				ans[size++]="O-";
			}
		}
	}
	
	return size;
}

int main(){
	int size=0;
	string ans[8];
	for(int i=0;i<8;i++){
		ans[i]="";
	}
	int counter=1;
	bool minus=true;
	bool minus2=true;
	bool A[2];
	bool B[2];
	bool O[2];
	for(int i=0;i<2;i++){
		A[i]=false;
		B[i]=false;
		O[i]=false;
	}
	string parents[2];
	string child;
	string temp;
	string temp2;
	string temp3;
	
	cin >> parents[0];
	cin >> parents[1];
	cin >> child ;
	temp=parents[0]+parents[1]+child;
	
	while(temp!="END"){
		if(child=="?"){
			for(int i=0;i<2;i++){
				temp=parents[i].substr(0,(parents[i].length())-1);
				temp2=parents[i].substr((parents[i].length())-1);
				if(temp2=="+"){
					minus=false;
				}
				if(temp=="AB"){
					A[i]=true;
					B[i]=true;
				}
				else if(temp=="O"){
					O[i]=true;
				}
				else if(temp=="A"){
					A[i]=true;
					O[i]=true;
				}
				else if(temp=="B"){
					B[i]=true;
					O[i]=true;
				}
			}
			size=getAnswer(A,B,O,minus,ans);
			
			cout << "Case " << counter << ": ";
			cout << parents[0] << " " << parents[1] << " ";
			if(size>1){
				cout << "{";
				for(int i=0;i<size;i++){
					if(i>0){
						cout << ", ";
					}
					cout << ans[i];
				}
				cout << "}" << endl;
			}
			else if (size==1){
				cout << ans[0] << endl;
			}
			else{
				cout << "IMPOSSIBLE" << endl;
			}
		}
		else if(parents[0]=="?"){
		
			temp=parents[1].substr(0,(parents[1].length())-1);
			temp2=parents[1].substr((parents[1].length())-1);
			if(temp2=="+"){
				minus=false;
			}
		
			temp3=child.substr(0,(child.length())-1);
			temp2=child.substr((child.length())-1);
			if(temp2=="+"){
				minus2=false;
			}
			minus2=(minus)&&(!minus2);
			size=getAnswer2(temp,temp3,minus2,ans);
			
			cout << "Case " << counter << ": ";
			if(size!=0){
				cout << "{";
				for(int i=0;i<size;i++){
					if(i>0){
						cout << ", ";
					}
					cout << ans[i];
				}
				cout << "} ";
			}
			else{
				cout << "IMPOSSIBLE ";
			}
			cout << parents[1] << " " << child << endl;
		}
		else if(parents[1]=="?"){
		
			temp=parents[0].substr(0,(parents[0].length())-1);
			temp2=parents[0].substr((parents[0].length())-1);
			if(temp2=="+"){
				minus=false;
			}
		
			temp3=child.substr(0,(child.length())-1);
			temp2=child.substr((child.length())-1);
			if(temp2=="+"){
				minus2=false;
			}
			minus2=(minus)&&(!minus2);
			size=getAnswer2(temp,temp3,minus2,ans);
			
			cout << "Case " << counter << ": ";
			cout << parents[0] << " ";
			if(size!=0){
				cout << "{";
				for(int i=0;i<size;i++){
					if(i>0){
						cout << ", ";
					}
					cout << ans[i];
				}
				cout << "} ";
			}
			else{
				cout << "IMPOSSIBLE ";
			}
			cout << child << endl;
		}
		
		
		
		size=0;
		counter++;
		minus=true;
		minus2=true;
		for(int i=0;i<2;i++){
			A[i]=false;
			B[i]=false;
			O[i]=false;
		}
		for(int i=0;i<8;i++){
			ans[i]="";
		}
		cin >> parents[0];
		cin >> parents[1];
		cin >> child ;
		temp=parents[0]+parents[1]+child;
	}
	return 0;
}
