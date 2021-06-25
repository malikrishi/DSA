/*
Problem : 
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Solution :
Keep two pointers , one left and one right 
Keep the height that is minimum.
Calculate the area :
    (right - left) * height,
    Now look for bar whose heoght is greater than previous bar from both directions until left crosses right and kepp track of maximum area
*/

class Solution {
public:
int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};
