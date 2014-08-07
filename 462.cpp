//Steven Kester Yuwono - UVa 462 - Bridge Hand Evaluator

#include <iostream>
#include <string>
using namespace std;

int getValue(int C[], int D[], int H[], int S[], char tempChar, char tempChar2){
	if(tempChar=='A'){
		if(tempChar2=='C'){
			C[0]=C[0]+4;
			C[4]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+4;
			D[4]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+4;
			H[4]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+4;
			S[4]=1;
		}
		return 4;
	}
	else if(tempChar=='K'){
		if(tempChar2=='C'){
			C[0]=C[0]+3;
			C[3]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+3;
			D[3]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+3;
			H[3]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+3;
			S[3]=1;
		}
		return 3;
	}
	else if(tempChar=='Q'){
		if(tempChar2=='C'){
			C[0]=C[0]+2;
			C[2]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+2;
			D[2]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+2;
			H[2]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+2;
			S[2]=1;
		}
		return 2;
	}
	else if(tempChar=='J'){
		if(tempChar2=='C'){
			C[0]=C[0]+1;
			C[1]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+1;
			D[1]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+1;
			H[1]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+1;
			S[1]=1;
		}
		return 1;
	}
	return 0;
}

void countCards(int C[], int D[], int H[], int S[], char tempChar){
	if(tempChar=='C'){
		C[5]++;
	}
	else if(tempChar=='D'){
		D[5]++;
	}
	else if(tempChar=='H'){
		H[5]++;
	}
	else if(tempChar=='S'){
		S[5]++;
	}
}

void checkCond(int &ans, int valueSuit[]){
	if(valueSuit[5]==1){
		if((valueSuit[3]==1)||(valueSuit[2]==1)||(valueSuit[1]==1)){
			ans--;
		}
	}
	else if(valueSuit[5]==2){
		if((valueSuit[2]==1)&&(valueSuit[1]==1)){
			ans--;
			ans--;
		}
		else if((valueSuit[2]==1)||(valueSuit[1]==1)){
			ans--;
		}
		
	}
	else if (valueSuit[5]==3){
		if(valueSuit[1]==1){
			ans--;
		}
	}
}

void checkCond2(int &ans, int valueSuit[]){
	if(valueSuit[5]==0){
		ans=ans+2;
	}
	else if(valueSuit[5]==1){
		ans=ans+2;
	}
	else if(valueSuit[5]==2){
		ans=ans+1;
	}
}

bool isNoTrump(int ans, int valueSuit[]){
	//cout << valueSuit[1] << valueSuit[2] << valueSuit[3] << valueSuit[4] << endl;
	if (ans<16){
		return false;
	}
	if (valueSuit[5]==1){
		if (valueSuit[4]==1){
			//cout << "A" << endl;
			return true;
		}
	}
	if (valueSuit[5]==2){
		if((valueSuit[3]==1)||(valueSuit[4]==1)){
			//cout << "B" << endl;
			return true;
		}
	}
	if(valueSuit[5]>=3){
		if((valueSuit[2]==1)||(valueSuit[3]==1)||(valueSuit[4]==1)){
			//cout << "C" << endl;
			return true;
		}
	}
	//cout << "D" << endl;
	return false;
}

char getCharMaxBid(int numC, int numD, int numH, int numS){
	if((numS>=numC)&&(numS>=numD)&&(numS>=numH)){
		return 'S';
	}
	if((numH>=numC)&&(numH>=numD)&&(numH>=numS)){
		return 'H';
	}
	if((numD>=numC)&&(numD>=numS)&&(numD>=numH)){
		return 'D';
	}
	if((numC>=numS)&&(numC>=numD)&&(numC>=numH)){
		return 'C';
	}
	return ' ';
}

int main(){
	string cards;
	
	int i=0;
	int ans=0;
	int valueC[6];
	int valueD[6];
	int valueH[6];
	int valueS[6];
	bool noTrumpC=0;
	bool noTrumpD=0;
	bool noTrumpH=0;
	bool noTrumpS=0;
	for(int j=0;j<6;j++){
		valueC[j]=0;
		valueD[j]=0;
		valueH[j]=0;
		valueS[j]=0;
	}
	while(getline(cin,cards,' ')){
		//cout << cards << endl;
		ans=ans+getValue(valueC,valueD,valueH,valueS,cards[0],cards[1]);
		//cout << "ans" << ans << endl;
		countCards(valueC,valueD,valueH,valueS,cards[1]);
		i++;
		while(i<13){
			if(i==12){
				getline(cin,cards);
			}
			else{
				getline(cin,cards,' ');
			}
			//cout << cards << endl;
			ans=ans+getValue(valueC,valueD,valueH,valueS,cards[0],cards[1]);
			//cout << "ans" << ans << endl;
			countCards(valueC,valueD,valueH,valueS,cards[1]);
			i++;
		}
		/*
		cout << "numC " << valueC[5] << endl;
		cout << "numD " << valueD[5] << endl;
		cout << "numH " << valueH[5] << endl;
		cout << "numS " << valueS[5] << endl;
		cout << "valueC "<< valueC[0] << endl;
		cout << "valueD "<< valueD[0] << endl;
		cout << "valueH "<< valueH[0] << endl;
		cout << "valueS "<< valueS[0] << endl;
		*/
		
		
		
		checkCond(ans,valueC);
		checkCond(ans,valueD);
		checkCond(ans,valueH);
		checkCond(ans,valueS);
		
		//cout << ans << endl;
		
		noTrumpC=isNoTrump(ans,valueC);
		noTrumpD=isNoTrump(ans,valueD);
		noTrumpH=isNoTrump(ans,valueH);
		noTrumpS=isNoTrump(ans,valueS);
		checkCond2(ans,valueC);
		checkCond2(ans,valueD);
		checkCond2(ans,valueH);
		checkCond2(ans,valueS);
	
		/*
		cout << "isstopC " << noTrumpC << endl;
		cout << "isstopD " << noTrumpD << endl;
		cout << "isstopH " << noTrumpH << endl;
		cout << "isstopS " << noTrumpS << endl;
		*/
		//cout << ans << endl;
		
		
		if((noTrumpC)&&(noTrumpD)&&(noTrumpH)&&(noTrumpS)){
			cout << "BID NO-TRUMP" << endl;
		}
		else if(ans<14){
			cout << "PASS" << endl;
		}
		else{
			cout << "BID " << getCharMaxBid(valueC[5],valueD[5],valueH[5],valueS[5]) << endl;
		}
		
		i=0;
		ans=0;
		noTrumpC=false;
		noTrumpD=false;
		noTrumpH=false;
		noTrumpS=false;
		for(int j=0;j<6;j++){
			valueC[j]=0;
			valueD[j]=0;
			valueH[j]=0;
			valueS[j]=0;
		}
	}
	return 0;
}
