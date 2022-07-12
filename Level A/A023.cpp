/*
Leet Code
<258. Add Digits>

Given an integer num, repeatedly add all its digits
until the result has only one digit, and return it.
=====================================================
Example 1:
Input: num = 38
Output: 2

Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0
=====================================================
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        int result = divide(num);
        while(result >= 10){ // 한자리 수가 될 때까지 계속 나눠줌...
            result = divide(result);
        }
        return result;
    }
    int divide(int num){
        int r = 0;
        while(num > 0){
            r += num % 10;
            num /= 10;
        }
        return r;
    }
};

int main()
{
    int result = Solution().addDigits(199);
    cout << result;
    return 0;
}