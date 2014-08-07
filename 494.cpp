#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    int count=0;
    
    while(getline (cin,line)) {
          int size =line.size();
          for(int i=0;i<size;i++){
                  if((line[i]>='A' && line[i]<='Z')||(line[i]>='a' && line[i]<='z')){
                              count++;
                              while(((line[i]>='A' && line[i]<='Z')||(line[i]>='a' && line[i]<='z')) && i<size){
								  i++;
							  }
                  }
                  
          }
          cout<<count<<endl;
          count=0;
    }

 return 0;
}
