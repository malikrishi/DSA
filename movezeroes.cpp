#include<iostream>
using namespace std;

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Solution : 
Move all thenon -zeros elements before the zeroes. ie. skip the 0s and then loop through the remaining and add 0s

*/

void moveZeroes(vector<int>& nums) {

    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
       if(nums[i]) {
            nums[j] = nums[i];
            j++;
        }
    } 
    while(j < nums.size()) {
        nums[j] = 0;
        j++;
    }

}

int main(){
}
