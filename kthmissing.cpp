/* 
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.


Solution : Apply binary search and check whthere the number of missing elements are less than the value of k, if it is search the right half else search the left half.
The answer is k + index where the search stops. Special handling if k < index at 0th position or arr[arr.size() -1 ] == arr.szie()
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0] > k) return k;
        if(arr[arr.size() - 1] == arr.size()) return arr[arr.size() - 1] + k;
        int l = 0;
        int r = arr.size()-1;
        
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            if (k > (arr[mid] - (mid + 1))) {
                l = mid + 1;
            }
            else {
                r = mid -1 ;
            }
        }
    
       return l + k;
    }
};
