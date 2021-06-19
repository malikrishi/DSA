/* 
Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (int i = 0 ; i < magazine.length(); i++) {
            m[magazine[i]] += 1;
        }
        //see if we can construct
        for (int i = 0; i< ransomNote.length(); i++) {
            m[ransomNote[i]] -= 1;
            if(m[ransomNote[i]] < 0) 
                return false;
            
        }
        return true;
    }
};
