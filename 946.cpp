//Steven Kester Yuwono - UVa 946

#include <iostream>
#include <vector>
using namespace std;

struct Box {
	int height;
	int contentHeight;
	vector<Box> content;
};

void initBox(int h, Box &box){
	box.height = h;
	box.contentHeight = 0;
	box.content.clear();
}

bool insert(Box &boxOuter, Box &boxInner){
	for(int i=0;i<(int)boxOuter.content.size();i++){
		if(insert(boxOuter.content[i],boxInner)) {
			return true;
		}
	}
	if(boxInner.height > boxOuter.height-boxOuter.contentHeight){
		return false;
	}
	boxOuter.contentHeight += boxInner.height;
	boxOuter.content.push_back(boxInner);
	return true;
}

int main(){
	int n;
	Box* boxPtr;
	while(cin >> n){
		boxPtr = new Box();
		initBox(2000000000,*boxPtr);
		for(int i=0;i<n;i++){
			int height;
			cin >> height;
			Box newBox;
			initBox(height,newBox);
			insert(*boxPtr,newBox);
		}
		cout << (*boxPtr).contentHeight << endl;
	}
	return 0;
}