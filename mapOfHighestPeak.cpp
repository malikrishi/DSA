/*

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.


Solution : 
Start from the water cells and apply BFS in all 4 directions of the cell (i-1, j), (i + 1, j), (i. j-1), (i, j+ 1), at each level update the cell with the levels.
Initally start all the cells except water calls with INT_MAX, check if height is less the current value. This will ensure the cell is visited only once.
Time Complexity O(Rows*Columns)


*/

class Solution {
public:
 vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), dir[5] = {0, 1, 0, -1, 0}, INF = 1e6+1;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j]) {
                    isWater[i][j]=0;
                    q.push({i, j});
                } else {
                    isWater[i][j]=INF;
                }
            }
        }
        int height = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto cur = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                    int r = cur.first + dir[i], c = cur.second + dir[i+1];
                    if(r < 0 || c < 0 || r >= m || c >= n) {
                        continue;
                    }
                    if(height < isWater[r][c]) {
                        isWater[r][c] = height;
                        q.push({r,c});
                    }
                }
            }
            height++;
        }
        return isWater;
    }
};
