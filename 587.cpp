// Steven Kester Yuwono - UVa 587

#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	int tc = 1;
	string line;
	while(getline(cin,line) && (line != "END")) {
		double x = 0;
		double y = 0;
		istringstream istream2(line);
		getline(istream2,line,'.');
		istringstream istream(line);
		string command;
		while(getline(istream,command,',')) {
			int cutIndex = -1;
			for(int i=0;i<(int)command.length();i++) {
				if(isalpha(command[i])) {
					cutIndex = i;
					break;
				}
			}
			string stepStr = command.substr(0,cutIndex);
			string direction = command.substr(cutIndex);
			double steps = atof(stepStr.c_str());
			double diagSteps = sqrt((steps*steps)/2.0);

			if (direction == "N") { y+=steps; }
			else if (direction == "NE") { x+=diagSteps; y+=diagSteps; }
			else if (direction == "E") { x+=steps; }
			else if (direction == "SE") { x+=diagSteps; y-=diagSteps; }
			else if (direction == "S") { y-=steps; }
			else if (direction == "SW") { x-=diagSteps; y-=diagSteps; }
			else if (direction == "W") { x-=steps;  }
			else if (direction == "NW") { x-=diagSteps; y+=diagSteps; }
		}

		printf( "Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n",tc++,x,y,sqrt(x*x+y*y));
	}
	return 0;
}