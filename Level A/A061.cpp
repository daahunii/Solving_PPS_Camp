/*
Leet Code
<168. Excel Sheet Column Title>

Given an integer columnNumber,
return its corresponding column title as it appears in an Excel sheet.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
=========================================================================
Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 701
Output: "ZY"
=========================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int n = columnNumber;
        
        while(n){
            ans.insert(ans.begin(), 'A' + (n-1)%26);
            n = (n-1)/26;
        }
        return ans;
    }
};

int main()
{
    string result = Solution().convertToTitle(701);
    cout << result;
    return 0;
}