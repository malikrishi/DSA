/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Input: n = 3
Output: 5

Solution : 
This is an application of catalan numbers. See the formula below.

Time complexity O(n2)

There is another formula for this in which the complexity is O(n)
Refer : 
https://www.geeksforgeeks.org/program-nth-catalan-number/
*/

#include<iostream>
#include<vector>
using namespace std;


int numTrees(int n) {
    // 0 -> 1
    // 1 -> 1
    // 2 -> 0*1 + 1*0 //Trees
    // 3 -> 0*2 + 1*1 + 2*0 //Trees
    // 4 -> 0*3 + 1*2 + 2*1 + 3*0
    // 5 -> 0*4 + 1*3 + 2*2 + 3*1 + 4*0
    
    vector<int> val(n + 1, 0);
    val[0] = 1;
    val[1] = 1;
    for (int i = 2 ; i <= n; i++) {
        int l = 0;
        int r = i-1;
        int num = i;
        while(num > 0) {
            val[i] += val[l]*val[r];
            l++;
            r--;
            num--;
        }
    }
    return val[n];
}


int main(){
   cout << numTrees(5) << endl;
   return 0;
}
