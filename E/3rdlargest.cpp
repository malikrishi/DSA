/* 
Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.


Solution : 
Iterate over each element 1 by 1.
For each element check if it is greater than the max element, it is then make it as max and swap the 2nd larget with the largest and the 3rd largest with 2nd largest.
Check for duplicates as well.
In the end check if we have the 3rd largest and return that else return the max element
*/


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a, b, c;
        a = b = c = LLONG_MIN;
        for(auto n : nums) {
            if(a == LLONG_MIN || n > a) {
                c = b;
                b = a;
                a = n;
            } else if (n != a && (b == LLONG_MIN || n > b) ) {
                c = b;
                b = n;
            } else if ((n != a && n != b) && (c == LLONG_MIN || n > c)) {
                c = n;
            }
            cout << " a " << a << " b " << b << " c " << c << endl;
        }
        if (c == LLONG_MIN) {
            return a;
        }
        return c;
    
    }
};
