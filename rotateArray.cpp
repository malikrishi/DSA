/* Problem :

Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Solution :
Approach 1 : 

Shift the elements by 1 k times. Complexity O(nk)

Approach 2.
Reverse the n-k elements.  4 3 2 1 5 6 7
Reverse the last k elements.4 3 2 1 7 6 5
Revers the complete array  5 6 7 1 2 3 4

*/

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

void rotateArray(vector<int> &nums, int k) {
    reverse(nums.begin(), nums.begin() + nums.size() - k );
    reverse(nums.begin() + nums.size() - k , nums.end());
    reverse(nums.begin(), nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotateArray(nums, 3);
    for(auto it : nums) {
        cout << it << " " ; 
    }
        cout << endl; 

    return 0;
}
