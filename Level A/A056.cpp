/*
Leet Code
<496. Next Greater Element I>

The next greater element of some element x
in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays
nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j]
and determine the next greater element of nums2[j] in nums2.
If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.
length such that ans[i] is the next greater element as described above. 
=======================================================================================
Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
=======================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    if(j+1 >= nums2.size()){ // 배열 사이즈를 초과해서 다음 큰 수가 없는 경우
                        result.push_back(-1);
                        break;
                    }
                    int nextchk = 0; // 더 큰 숫자가 있는지 체크용 
                    for(int k=j+1; k<nums2.size(); k++){ // 다음 숫자를 하나하나 검사해 찾아서
                        if(nums2[j] < nums2[k]){
                            result.push_back(nums2[k]); // 찾으면 수를 넣고 체크
                            nextchk = 1;
                            break;
                        }
                        else nextchk = 0;
                    }
                    if(nextchk == 0){   // 못 찾은 경우 -1 추가
                        result.push_back(-1);
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> n1 = {1,3,5,2,4};
    vector<int> n2 = {6,5,4,3,2,1,7};
    vector<int> result = Solution().nextGreaterElement(n1, n2);
    for(int i=0; i<result.size(); i++) cout << result[i] << endl;
    return 0;
}