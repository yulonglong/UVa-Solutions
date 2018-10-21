// Steven Kester Yuwono
// National Olympiad in Informatics Singapore (NOI) 2018
// Task 1 - Collecting Mushrooms

#include <bits/stdc++.h>
using namespace std;
#define MSIZE 500010

vector<vector<char> > board;
vector<vector<int> > horizontalBoardCount;
vector<vector<int> > boardCount;

int getNumSprinklerGivenMushroom(int x, int y, int d) {
    int maxX = x+d;
    if (maxX >= board.size() ) maxX = board.size()-1;
    int maxY = y+d;
    if (maxY >= board[0].size() ) maxY = board[0].size()-1;

    int numSprinkler = boardCount[maxX][maxY];
    int minX = x-d-1;
    if (minX >= 0) numSprinkler -= boardCount[minX][maxY];
    int minY = y-d-1;
    if (minY >= 0) numSprinkler -= boardCount[maxX][minY];
    if (minX >= 0 && minY >= 0) numSprinkler += boardCount[minX][minY];
    return numSprinkler;
}

int main() {
    int r,c,d,k;
    scanf("%d %d %d %d", &r, &c, &d, &k);
    for (int i=0;i<r;i++) {
        vector<char> currRow;
        board.push_back(currRow);
        vector<int> currRowCount;
        horizontalBoardCount.push_back(currRowCount);

        char currStr[MSIZE];
        scanf("%s\n", currStr);
        for (int j=0;j<c;j++) {
            board[i].push_back(currStr[j]);
            if (j == 0 && currStr[j] == 'S') horizontalBoardCount[i].push_back(1);
            else if (j == 0) horizontalBoardCount[i].push_back(0);
            else if (currStr[j] == 'S') horizontalBoardCount[i].push_back(horizontalBoardCount[i][j-1]+1);
            else horizontalBoardCount[i].push_back(horizontalBoardCount[i][j-1]);
        }
    }

    for (int j=0;j<c;j++) {
        for (int i=0;i<r;i++) {
            if (j==0) {
                vector<int> currRowCount;
                boardCount.push_back(currRowCount);
            }
            if (i==0) boardCount[i].push_back(horizontalBoardCount[i][j]);
            else boardCount[i].push_back(horizontalBoardCount[i][j]+boardCount[i-1][j]);
        }
    }

    int ans = 0;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (board[i][j] == 'M') {
                if (getNumSprinklerGivenMushroom(i,j,d) >= k) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
