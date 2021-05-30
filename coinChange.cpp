/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Solution :
Create a DP 1d table of size amount + 1
dp[0] = 1; //Base Case.
Assign all others to amount +1 

Loop through all the coins(j) one by one for each amount(i)
Assign dp[i] = min(dp[i], dp[i - coins[j]) 

return dp[amount] if it less or eqaul to amount else return -1
*/
#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

int main(){

    vector<int> coins(2,0);
    coins[0] = 1;
    coins[1] = 2147483647;
    cout << coinChange(coins, 2) << endl;

}
