/* 
Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*/

class Solution {
public:
    /* Simple square and sort O(nlogn)
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for (auto it : nums) {
            result.push_back(it * it);
        }
        sort(result.begin(), result.end());
        return result;
    }
    */
    //Two pointer apporach
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> result(nums.size(), 0);

        int i = nums.size() -1;
        
        //Compare left and right absolute pointer elements and add result on the basis of which one is greater.
        while(left <= right) {
            if(abs(nums[left]) < abs(nums[right])) {
                result[i] = nums[right] * nums[right];
                right--;
            } else {
                result[i] = nums[left] * nums[left];
                left++;
            }
            i--;
        }
        return result;
    }
};
