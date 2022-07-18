/*
Leet Code
<14. Longest Common Prefix>

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
========================================================================================
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
========================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = 201;
        string str = "";
        bool flag = true;
        char tmp;
        
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].length() < min) min = strs[i].length();
        }
        for(int i = 0; i < min; i++){ 
            tmp = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(tmp == strs[j][i]){
                    if(j == (strs.size()-1))
                    str += strs[j][i];  
                    continue;
                }
                else{
                    flag = false;
                    break;
                }  
            }
            if(!flag) break;
        }
        return str;
    }
};

int main()
{
    vector<string> v = {"flower","flow","flight"};
    string result = Solution().longestCommonPrefix(v);
    cout << result;
    return 0;
}