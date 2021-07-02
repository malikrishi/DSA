/*
Given an array nums of non-negative integers, return an array consisting of all the even elements of nums, followed by all the odd elements of nums.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Solution :
Take two pointers : 
evenIdx and oddIdx. Start from the end and see if it is an odd number, do nothing and decrement the oddIdx.
If it is even , swap with evenIdx and increment evenIdx. 
Repeat until evenIdx <= oddIdx
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() == 0) return nums;
        int evenIdx = 0;
        int oddIdx = nums.size()-1;
        
        while(evenIdx <= oddIdx) {
            if (nums[oddIdx] % 2) oddIdx--;
            else {//Swap it with the even Idx
                int temp = nums[oddIdx];
                nums[oddIdx] = nums[evenIdx];
                nums[evenIdx] = temp;
                evenIdx++;
            }
        }
        return nums;
    }
};
