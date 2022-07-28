/*
Leet Code
<1051. Height Checker>

A school is trying to take an annual photo of all the students.
The students are asked to stand in a single file line in non-decreasing order by height.
Let this ordering be represented by the integer array expected
where expected[i] is the expected height of the ith student in line.
You are given an integer array heights representing the current order that the students are standing in.
Each heights[i] is the height of the ith student in line (0-indexed).
Return the number of indices where heights[i] != expected[i]. 
=========================================================================================================
Example 1:
Input: heights = [1,1,4,2,1,3]
Output: 3

Example 2:
Input: heights = [5,1,2,3,4]
Output: 5

Example 3:
Input: heights = [1,2,3,4,5]
Output: 0
=========================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> r;
        r = heights;
        sort(r.begin(), r.end());
        
        int cnt = 0;
        for(int i=0; i<r.size(); i++) if(heights[i] != r[i]) cnt++;
        // for(int i=0; i<r.size(); i++) cout << r[i] << " ";
        return cnt;
    }
};

int main()
{
    vector<int> v = {5,4,3,2,1};
    int result = Solution().heightChecker(v);
    cout << result;
    return 0;
}