/*
Leet Code
<844. Backspace String Compare>

Given two strings s and t, return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.
======================================================================================================
Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
======================================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
    
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#' && !a.empty()) a.pop_back();
            else if (s[i] != '#') a += s[i];
        }
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '#' && !b.empty()) b.pop_back();
            else if (t[i] != '#') b += t[i];
        }
        return a == b;
    }
};

int main()
{
    bool result = Solution().backspaceCompare("ab#c", "ad#c");
    cout << result;
    return 0;
}