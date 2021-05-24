/*

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Solution : Keep track of the maximum index you can reach till now. Keep updating it if the max you can reach from the current index is higher than the current max.
If at any point current index is equal to max_reach and it's value is 0 then break.

After looping the array just chaeck if max is >= length

*/

#include<iostream>
using namespace std;

bool canJump(vector<int> &nums) {

    int maxReach = 0;
    //Loop till second last index since we need to reach the last index
    for (int i = 0; i < nums.size() - 1; i++) {
        if((nums[i] + i ) > max_reach) {
            maxReach = nums[i] + i;
        }
        if(nums[i] + i == maxReach && nums[i] == 0) break;
    }
    if (maxReach >= nums.size() -1 ) return true;
    return false;


}

int main() {

}
