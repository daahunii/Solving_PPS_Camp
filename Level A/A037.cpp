/*
Leet Code
<728. Self Dividing Numbers>

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, 
return a list of all the self-dividing numbers in the range [left, right].
=================================================================================================
Example 1:
Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

Example 2:
Input: left = 47, right = 85
Output: [48,55,66,77]
=================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left; i<=right; i++){
            bool selfDividing = true;
            int num = i;
            while(num){
                if(num%10 == 0 || i%(num%10) != 0){ // 0이 포함되어 있거나 그 수가 나눠지지 않는 경우
                    selfDividing = false;
                    break;
                }
                num/=10; // 다음 자릿수로...
            }
            if(selfDividing) result.push_back(i);
        }
        return result;
    }
};

int main()
{
    vector<int> result = Solution().selfDividingNumbers(1, 22);
    cout << "[";
    for(int i=0; i<result.size(); i++){
        cout << result[i];
        if(i < result.size()-1) cout << ",";
    }
    cout << "]";
    return 0;
}