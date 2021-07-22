/* 
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Solution : Backtracking

Complexity : O((number of candidates)^(target/min of candidates))
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //Sort the vector
        sort(candidates.begin(), candidates.end());
        //use backtracking.
        vector<vector<int>> res;
        int pos = 0;
        vector<int> combination;
        combinationsumBT(candidates, target, res, combination, pos);
        return res;
    }
    void combinationsumBT(vector<int> candidates, int target, vector<vector<int>> &res, vector<int> &combination,  int pos) {
        if (target == 0 ){
            res.push_back(combination);
            return;
        }
        
        for (int i=pos; i < candidates.size() && target >= candidates[i] ; i++) {
            combination.push_back(candidates[i]);
            combinationsumBT(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
