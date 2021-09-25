/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

*/
class Solution {
public:
    /* O(nlogn) */
    int getNosOfOnes(int n) {
        int res = 0;
        while(n > 0) {
                if (n%2 != 0 ) //Count only if number is not exactly divisble by 2
                    res++;
                n = n/2;
            }
        
        return res;
    }
    /* vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++){
            //Get number of 1's
            res.push_back(getNosOfOnes(i));
        }
        return res;
    } */
    /* O(n) solution with DP 
    
    dp[0] = 0
    dp[1] = 1
    dp[2] = 1 + dp[0]
    dp[3] = 1 + dp[1]
    dp[4] = 1 + dp[0]
    dp[5] = 1 + dp[1]
    dp[6] = 1 + d[2]
    dp[7] = 1 + dp[3]
    dp[8] = 1 + dp[0]
    
    
    */
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        if (n == 0) return res;
        res[0] = 0;
        res[1] = 1;
        if (n == 1) return res;
        
        int nearestPower = 0;
        int curr = 2;
        while(curr <= n){
            if((curr & (curr -1)) == 0) {
                nearestPower = curr;
            }
            res[curr] = 1 + res[curr - nearestPower];
            curr++;
        }
        return res;
    }
};
