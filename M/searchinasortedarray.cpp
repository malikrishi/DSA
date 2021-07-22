/* Solution 
 Approcah 1: Find the location at which the element is rotated
and then apply binary search on it.

Approach 2 : Check and compare the values of mid with left , right and which part the target lies, 
adjust , left/ right accordingly

*/

/*
Approach 1

class Solution {
    public int search(int[] nums, int target) {
        if(nums==null || nums.length==0) return -1;
        int l=0, r=nums.length-1, m=0;
       // find out the index of the smallest element.
        while(l<r){
            m = (l+r)/2;
            if(nums[m] > nums[r]){
                l = m+1;
            }else{
                r = m;
            }
        }
        
       // since we now know the start, find out if the target is to left or right of start in the array.
        int s = l;
        l = 0; r = nums.length-1;
        if(target >= nums[s] && target <= nums[r]){
            l = s;
        }else{
            r = s;
        }
        // the regular search.
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]==target) return m;
            else if(nums[m] > target) r = m-1;
            else l=m+1;
        }
        
        return -1;
    }
}
*/
class Solution {
public:
    int search(vector<int>& arr, int no) {
        int low = 0;
        int high = arr.size()-1;
        
        while (low <= high)
        {//0 1 mid = 0
            int mid = (low + high )/ 2;
            if (arr[mid] == no) return mid;
            else if (arr[mid] < arr[high] )
            {
                if( no > arr[mid] && no <= arr[high])  { low = mid + 1;}
                else {high = mid - 1;}      
            }
            else { 
                if (no >= arr[low] && no < arr[mid]) {high = mid - 1;}
                else {low = mid + 1;}
            }
        }
        return -1;
    }
};
