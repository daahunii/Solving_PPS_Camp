/*
Leet Code
<860. Lemonade Change>

At a lemonade stand, each lemonade costs $5. 
Customers are standing in a queue to buy from you and order one at a time
(in the order specified by bills). 
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is 
that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays,
return true if you can provide every customer with the correct change, or false otherwise.
===================================================================================================
Example 1:
Input: bills = [5,5,5,10,20] // 거슬러줄 잔돈 o
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:
Input: bills = [5,5,10,10,20] // 마지막에 거슬러줄 잔돈 x
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
===================================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coins = {0, 0, 0}; // $5, $10, $20

        for(int bill : bills){
            if(bill == 5) coins[0] += 1;
            else if(bill == 10){
                if(coins[0] >= 1){
                    coins[0] -= 1; // give $5
                    coins[1] += 1; // give back $10
                }
                else return false;
            }
            else if(bill == 20){
                if(coins[1] >= 1 && coins[0] >= 1){
                    coins[1] -= 1; // first calculate $10
                    coins[0] -= 1; // and then give $5
                    coins[2] += 1; // give back $20
                }
                else if(coins[0] >= 3) coins[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> v = {5,5,5,10,20};
    bool result = Solution().lemonadeChange(v);
    cout << result;
    return 0;
}