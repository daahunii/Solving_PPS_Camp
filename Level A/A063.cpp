/*
Leet Code
<67. Add Binary>

Given two binary strings a and b, return their sum as a binary string.
======================================================================
Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

1. a와 b의 길이를 비교하여 긴 문자를 a로, 짧은 문자를 b로 만든다.
2. a와 b를 reverse한다.(연산을 쉽게 하기 위해)
3. a와 b를 b의 길이까지 비교하며 이진수 덧셈을 하며, 연산의 결과는 a에 저장한다.
4. a에서 (b의 길이, a의 길이)를 살펴보며 2 이상이면 자릿수를 올려준다.
5. a를 reverse하여 return
======================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
			string tmp = a;
			a = b;
			b = tmp;
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for(int i = 0; i < b.size(); i++){
			int na = a[i] - '0';
			int nb = b[i] - '0';
			if(na + nb > 1){
				a[i] = ('0' + na + nb - 2);
				if (i == a.size() - 1) a += "1";
				else a[i + 1]++;
			}
			else a[i] = ('0' + na + nb);
		}
		for(int i = b.size(); i < a.size(); i++) {
			if (a[i] == '2') {
				a[i] = '0';
				if (i == a.size() - 1) a += "1";
				else a[i + 1]++;
			}
			else break;
		}
		reverse(a.begin(), a.end());
		return a;
    }
};

int main()
{
    string result = Solution().addBinary("1010", "1011");
    cout << result;
    return 0;
}