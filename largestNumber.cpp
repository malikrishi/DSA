/*

Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

Solution : 
Conver the numbers to string using to_string and put it in new vector and then sort by custom comparator
sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
In these type of sorting we sort the elements as per our choice by passing third argument in sort function.
For example:
In sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
[](string &s1, string &s2){ return s1+s2>s2+s1; }) this part has meaning that:
Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second in the specific strict weak ordering it defines.
The function shall not modify any of its arguments.
Given two numbers X and Y, decide which number to put first – we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before. For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.
if we have written the condition [](string &s1, string &s2){ return s1+s2<s2+s1; }) then our function has arranged the numbers of array in smallest number.

*/

class Solution {
public:
  string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};

