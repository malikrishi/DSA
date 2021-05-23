/*
Problem :: 
Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out the minimum steps a Knight will take to reach the target position.
*/


// Input : findSteps(int N, int N, int srcX, int srcY, int dstX, int dstY) 
// O/P : int (number of steps) 
/*
 
No of moves a knight can make : 8 and their coordiantes are 
XCoordinate[] = {-1, 1, 2, 2, 1, -1, -2, -2};
YCoordinate[] = {2, -2, -1, 1, 2, 2, 1, -1};

Push the current coordinate to a queue and see if that is equal to the destination corredinates.
If not, mark it as visited and push all the coordinates it can move in the next step.
Repeat until queue is empty and retun -1 in the end

*/

#include<iostream>
#include <queue>

using namespace std;

struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};

int XCoordinate[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int YCoordinate[] = {2, -2, -1, 1, 2, 2, 1, -1};

int isValid(int x, int y, int N) {
    if (x >= 0 && x < N && y >= 0 && y < N) return true;
    return false;
} 
int findSteps (int N, int SrcX, int SrcY, int DstX, int DstY) {
    int srcX = SrcX - 1;
    int srcY = SrcY - 1;
    int dstX = DstX - 1;
    int dstY = DstY - 1;

    //Create a queue of cell
    queue<cell> q;
    //Create a visited 2d Array to store the visited status and initialize to false
    vector<vector<bool> > visited(N);
    for(int i = 0; i < N ; i++) {
        visited[i] = vector<bool>(N);
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
                }
    }
    int dist = 0; //initial steps
    //Push the current coordinates to the queue
    q.push(cell(srcX, srcY, dist));
    //Mark it as visited
    visited[srcX ][srcY] = true;
    while (!q.empty() ) {
        cell val = q.front();
        q.pop();
        if(val.x == dstX && val.y == dstY) {
            return val.dis;
        } else {
            for(int i = 0 ; i < 8 ; i++) {
                //Push in the queue if not visited and is within the chess board
                int xCo = val.x + XCoordinate[i];
                int yCo = val.y + YCoordinate[i];
                if (isValid(xCo, yCo, N) && !visited[xCo][yCo] ) {
                    q.push(cell(xCo, yCo, val.dis + 1));
                    visited[xCo ][yCo ] = true;
                }
            }
        }   
    }
    return -1;
}


int main() {
    int N = 30;
    cout << findSteps (N, 1, 1, 30, 30) << endl;
    return 0;
}
