/* 
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.


Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"


Solution :
This is a string manipulation and recursion problem.
if n is 1 return "1" base case
Else loop through the string and check the count of each character and convert it to string and repeat for rest of the string and return
*/
class Solution {
public:
    string helperFunc(string s) {
        string res;
        int len = s.length();
        if (len == 1) return "1" + s;
        int i = 1;
        int cnt = 1;
        while(i <= len) {
            while(s[i-1] == s[i] && i < len) {
                cnt++;
                i++;
            }
            res = res + to_string(cnt) + s[i-1];
            i++;
            cnt = 1;
        }
        return res;
    }

    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string s = countAndSay(n-1);
        return helperFunc(s);
        
        
        
    }
};
