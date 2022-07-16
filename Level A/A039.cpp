/*
Leet Code
<367. Valid Perfect Square>

Given a positive integer num, write a function
which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.
====================================================================
Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false
====================================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long x = num;
        while(x * x > num){
            x = (x + num/x) >> 1;
        }
        return x*x == num;
    }
};

int main()
{
    bool result = Solution().isPerfectSquare(14);
    cout << result;
    return 0;
}