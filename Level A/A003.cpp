/*
Leet Code
<66. Plus One>

You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

==========================================================================================
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
==========================================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int crrIdx = digits.size() - 1;
        while(true){
            if(digits[crrIdx] == 9) { // 현재 자릿수의 수가 9이면
                digits[crrIdx] = 0; // 0으로 바꾸고
                if(crrIdx-1 >= 0) crrIdx--; // 맨 앞자리 수까지 앞자리 수로 전진
                else{ // 맨 앞자리수이면 젤 앞에 1추가
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
            else{
                digits[crrIdx]++;
                break;
            }
        }
        return digits;
    }
};

int main(){
    int a[]={9,9,9};
    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
    vector<int> v = Solution().plusOne(d);

    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    
    return 0;
}