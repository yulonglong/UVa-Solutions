//Steven Kester Y - UVa 12694

#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

typedef struct{
	int start;
	int end;
}time;

int permutate(time array[], bool occupied[],int count,int index,int size){
	if(index==size){
		return count;
	}

	bool newOccupied[10];
	for(int i=0;i<10;i++){
		newOccupied[i]=occupied[i];
	}
	int count1=count;
	int start=array[index].start;
	int duration=array[index].end-array[index].start;
	while((newOccupied[start]==false)&&(duration>0)){
			start++;
			duration--;
	}

	if(duration==0){
		start=array[index].start;
		duration=array[index].end-array[index].start;
		while(duration>0){
			newOccupied[start]=true;
			start++;
			duration--;
		}
		count1++;
	}

	if(count1==count){
		return permutate(array,occupied,count,index+1,size);
	}
	return max(permutate(array,newOccupied,count1,index+1,size),permutate(array,occupied,count,index+1,size));
}

int main(){

	int tc;
	scanf("%d",&tc);
	while(tc--){
		bool occupied[10];
		memset(occupied,false,sizeof occupied);
		time array[20];


		int N,M;
		time newTime;
		scanf("%d %d",&N,&M);

		int i=0;
		while(!((N==0)&&(M==0))){
			newTime.start=N;
			newTime.end=M;
			array[i++]=newTime;

			scanf("%d %d",&N,&M);
		}

		int result=permutate(array,occupied,0,0,i);
		printf("%d\n",result);
	}
}