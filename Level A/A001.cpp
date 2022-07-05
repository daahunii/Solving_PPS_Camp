/*
Leet Code
<455. Assign Cookies>

Assume you are an awesome parent and want to give your children some cookies.
But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie 
that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, 
and the child i will be content. Your goal is to maximize the number of your content children 
and output the maximum number.
=================================================================================================
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child 
whose greed factor is 1 content.
You need to output 1.
=================================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int sidx = 0;
        int cnt = 0;
        
        for(int i = 0; i < g.size(); i++) {
            for(int j = sidx; j < s.size(); j++) {
                if(g[i] <= s[j]){
                    sidx = j + 1;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main(){
    int g1[] = {1, 2, 3};
    vector<int> gv1(g1, g1 + sizeof(g1)/sizeof(int));
    int s1[] = {1, 1};
    vector<int> sv1(s1, s1 + sizeof(s1)/sizeof(int));
    cout << Solution().findContentChildren(gv1, sv1) << endl;

    int g2[] = {1, 2};
    vector<int> gv2(g2, g2 + sizeof(g2)/sizeof(int));
    int s2[] = {1, 2, 3};
    vector<int> sv2(s2, s2 + sizeof(s2)/sizeof(int));
    cout << Solution().findContentChildren(gv2, sv2) << endl;
    return 0;
}