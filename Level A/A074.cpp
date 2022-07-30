/*
Leet Code
<125. Valid Palindrome>

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
===========================================================================================
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: s = "race a car"
Output: false

Example 3:
Input: s = " "
Output: true
===========================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str("");
        for(int i=0;i<s.size();i++) if(isalnum(s[i])) str.push_back(tolower(s[i]));

        for(int i=0;i<str.size()/2;i++) if(str[i]!=str[str.size()-1-i]) return false;
        return true;
    }
};

int main()
{
    bool result = Solution().isPalindrome("race car");
    cout << result;
    return 0;
}