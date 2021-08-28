/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]

 
*/


/*
Theproblem can be divided in to different sub tasks
1. First find the pivot element in the array.
    The pivot element is the one that in the first non increasing number if we start from end.

2. Once we find the pivot, find the next largest number on the right of it in the array

3. Swap the two

4. Reverse the array from the after the pivot index.

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Find the pivot index
        int pivotIdx = getPivotIdx(nums);
        if (-1 == pivotIdx) {
            sort(nums.begin(), nums.end()) ;
            return;
        }
        
        
        //Find the next greater element index than the element at the pivot index
        int nextGreater = findNextGreater(nums, pivotIdx);
        if (-1 == nextGreater) {
            sort(nums.begin(), nums.end()) ;
            return;
        }
        
        //Swap the two elements
        swap(nums, pivotIdx, nextGreater);
        
        
        //Reverse arr
        reverse(nums, pivotIdx + 1);
        
    }
    
private :
    int getPivotIdx(vector<int> &nums) {
        int size = nums.size();
        for (int i = size - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                return i-1;
            }
        }
        return -1;
    }
    
    int findNextGreater(vector<int> &nums, int pivotIdx) {
        int size = nums.size();
        for (int i = size - 1; i > pivotIdx; i--) {
            if (nums[i] > nums[pivotIdx]) {
                return i;
            }
        }
        return -1;
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverse(vector<int> &nums, int start) {
        int end = nums.size();
        while(start < end - 1) {
            swap(nums, start, end - 1);
            start++;
            end--;
        }
        
    }
};
