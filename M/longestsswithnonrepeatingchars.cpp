/* 

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Solution : 
Keep a dict that's initialized of 256 chars that's initialized to  -1.
Keep track of the 1st index of every unique cashr uptil now and keep a max length which increments after avery unique character
When a repeting charater is encoountered, reset the index for it in the dict with the new since you cannot have duplicate chars,
*/
class Solution {
public:
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
