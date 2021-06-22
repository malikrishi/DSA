/*
Problem : 
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.


Solution : 
Use DP,
Create a 2d Array and assign true to all the diagonals(0,0  / 1,1 / 2,2 / 3,3)
if index of start and index of end has same values and the dp[row + 1] [column - 1] is true that means it already palindrome we mark dp[row][column] as true
to calculate the string, find the longest j - i which is true and return the substring

Refer : https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP
https://www.youtube.com/watch?v=WpYHNHofwjc
*/


class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[s.length()][s.length()];
        for(int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if(i == j) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        for(int column = 1; column < s.length(); column++) {
            for (int row = 0; row < column && row < s.length() - 1 ; row++) {
                if (column - row == 1) {
                    if (s[row] == s[column] ) dp[row][column] = true;
                }
                else {
                    if ((s[column] == s[row]) && dp[row + 1][column - 1] == true){
                        dp[row][column] = true;
                    }
                }
            }
        }
        int longest = 0;
        int R = 0;
        int C = 0;
        for(int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (dp[i][j]) {
                    if((j - i + 1) > longest ) {
                        longest = j - i + 1;
                        R = i;
                        C = j;
                    }
                }     
            }
        }
        
        return s.substr(R, C - R + 1);
    }
};
