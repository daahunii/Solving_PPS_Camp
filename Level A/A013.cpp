/*
Leet code
<136. Single Number>

Given a non-empty array of integers nums, 
every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

===================================================================================================
Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
===================================================================================================
*/

#include<iostream>
#include<vector>
using namespace std;

// bit 연산을 이용한 풀이!
class Solution {
public:
    int singleNumber(vector<int>&nums) {
        int res = 0;
		for (auto& num : nums) {
			res ^= num; // XOR 연산
		}
		return res;
    }
};

int main()
{
    vector<int> v = {2,2,1,4,5,4,1};
    cout << Solution().singleNumber(v);
    return 0;
}

// 비트가 같으면 0, 다르면 1이 되는 XOR 연산을 통해 쌍이 아닌 값을 뽑아 낼 수 있습니다.
// ((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5.