/*

Count pairs in a sorted array whose sum is less than x
Given a sorted integer array and number x, the task is to count pairs in array whose sum is less than x.
Examples: 
 

Input  : arr[] = {1, 3, 7, 9, 10, 11}
         x = 7
Output : 1
There is only one pair (1, 3)

Input  : arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
         x = 7
Output : 6
Pairs are (1, 2), (1, 3), (1, 4), (1, 5)
          (2, 3) and (2, 4)  



1) Initialize two variables l and r to find the candidate 
   elements in the sorted array.
       (a) l = 0
       (b) r = n - 1
2) Initialize : result = 0
2) Loop while l < r.

    // If current left and current
    // right have sum smaller than x,
    // the all elements from l+1 to r
    // form a pair with current
    (a) If (arr[l] + arr[r] < x)  
          result = result + (r - l)      
   
    (b) Else
            r--;
       
3) Return result

*/


// C++ program to count pairs in an array
// whose sum is less than given number x
#include<bits/stdc++.h>
using namespace std;
 
// Function to count pairs in array
// with sum less than x.
int findPairs(int arr[],int n,int x)
{
    int l = 0, r = n-1;
    int result = 0;
 
    while (l < r)
    {
        // If current left and current
        // right have sum smaller than x,
        // the all elements from l+1 to r
        // form a pair with current l.
        if (arr[l] + arr[r] < x)
        {
            result += (r - l);
            l++;
        }
 
        // Move to smaller value
        else
            r--;
    }
 
    return result;
}
 
