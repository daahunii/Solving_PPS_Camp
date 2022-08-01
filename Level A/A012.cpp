/*
Leet Code
<204. Count Primes>

Given an integer n, return the number of prime numbers
that are strictly less than n.
==============================================================================
Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
==============================================================================
Constraints:
0 <= n <= 5 * 10^6
==============================================================================
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int i = 0, j = 0;
        vector<int> v;

        if(n == 0 || n == 1) i = 0;
        else{
            for(i=2; i<n; i++){
                for(j=2; j<i; j++) if(i % j == 0) break;
                if(i == j) v.push_back(i);
            }
        }
        return v.size();
    }
};

int main()
{
    int result = Solution().countPrimes(499979);
    cout << result;
    return 0;
}

//*** other solution ***

// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n<=2)return 0;
        
//         vector<bool>isPrime(n+5);
//         for(int i=2;i<n+2;i++)
//         {
//             if(isPrime[i]==false)
//             {
//                 for(int j=i+i;j<n+2;j+=i)isPrime[j]=true;
//             }
//         }
//         int c=0;
//         for(int i=2;i<n;i++)if(!isPrime[i])c++;
//         return c;
//     }
// };