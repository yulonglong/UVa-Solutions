#include <iostream>
#include <sstream>
using namespace std;


int memory[100050];

int getLargest(int size){
    int sum=0;
    int max=0;
    for(int i=0;i<size;i++){
        //cout << memory[i] << endl;
        sum+=memory[i];
       
        if(max<sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return max;
}

int main(){
    string word;
    while(getline(cin,word)){
        istringstream istream(word);
        int counter=0;
        while(istream >> memory[counter++]){
          //  cout << memory[counter-1] << endl;
        }
        int max=getLargest(counter-1);
        cout << max << endl;
    }
    return 0;
}