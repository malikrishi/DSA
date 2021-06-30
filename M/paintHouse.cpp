/*

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

All costs are positive integers.

Example
Example 1:

Input: [[14,2,11],[11,14,5],[14,3,10]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. Minimum cost: 2 + 5 + 3 = 10.
Example 2:

Input: [[1,2,3],[1,4,6]]
Output: 3

Solution : 
DP problem,
Start from each of the colors.
1. Start from Red
2. Start from Green
3. Start from Blue.

In each of the next steps pick a color that is not the previous color and minimum of the remaining two colors cost plus the cost of previous color
and in the end compare each of the colors and return the min value.

*/

#include<iostream>
#include<vector>
using namespace std;

int findMinCost(vector<vector<int> > &costs) {

    int R = costs.size();
    int C = costs[0].size();

    vector<vector<int> > dp(R, vector<int>(C, 0));
    //The cost to paint the 1st house will always be what we got it in the costs matrix. This will be our base case for DP.
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    //Now apply DP on the rest of the houses by picking each of the three colors and minimum cost of previous different color house
    for(int i = 1; i < R; i++) {
 // If current house is colored
        // with red the take min cost of
        // previous houses colored with
        // (blue and green)
        dp[i][0] = min(dp[i - 1][1],
                       dp[i - 1][2])
                   + costs[i][0];
 
        // If current house is colored
        // with blue the take min cost of
        // previous houses colored with
        // (red and green)
        dp[i][1] = min(dp[i - 1][0],
                       dp[i - 1][2])
                   + costs[i][1];
 
        // If current house is colored
        // with green the take min cost of
        // previous houses colored with
        // (red and blue)
        dp[i][2] = min(dp[i - 1][0],
                       dp[i - 1][1])
                   + costs[i][2];
    }

    return min(dp[R-1][0], min(dp[R-1][1], dp[R-1][2]));
}

int main() {
    vector<vector<int> > costs{ { 14, 2, 11 },
                                { 11, 14, 5 },
                                { 14, 3, 10 } };

   cout << findMinCost(costs) << endl;
   return 0;
}
