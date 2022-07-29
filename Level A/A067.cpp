/*
Leet Code
<1047. Remove All Adjacent Duplicates In String>

You are given a string s consisting of lowercase English letters.
A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made.
It can be proven that the answer is unique.
===========================================================================================
Example 1:
Input: s = "abbaca"
Output: "ca"

Example 2:
Input: s = "azxxzy"
Output: "ay"
===========================================================================================
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;    
        for(int i=0; i<s.length(); i++){
            if(st.size() == 0) st.push(s[i]);
            else{
                if(st.top() == s[i]) st.pop();
                else st.push(s[i]);
            }
        }
        while(st.size() != 0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    string result = Solution().removeDuplicates("abbaca");
    cout << result;
    return 0;
}