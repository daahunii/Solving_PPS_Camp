/*
Leet Code
<1154. Day of the Year>

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD,
return the day number of the year.
===================================================================================
Example 1:
Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:
Input: date = "2019-02-10"
Output: 41

Constraints:
date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31th, 2019.
===================================================================================
*/

class Solution {
public:
    int dayOfYear(string date) {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> leap_months = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int year = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day = atoi(date.substr(8, 2).c_str());

        vector<int>& v = is_leap_year(year) ? leap_months : months; // 윤년인 년도인지...

        int res = 0;
        for(int i = 0; i < month - 1; i ++) res += v[i];
        return res + day;
    }

private:
    bool is_leap_year(int year){
        return (year % 4 == 0 && year % 100) || (year % 400 == 0);
    }
};

int main()
{
    cout << Solution().dayOfYear("2019-01-09") << endl; // 9
    cout << Solution().dayOfYear("2019-02-10") << endl; // 41
    cout << Solution().dayOfYear("2003-03-01") << endl; // 60
    cout << Solution().dayOfYear("2004-03-01") << endl; // 61
    return 0;
}