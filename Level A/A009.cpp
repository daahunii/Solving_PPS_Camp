/*
Programmers
<문자열 다루기 기본>

문제 설명

문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 
예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.

제한 사항
s는 길이 1 이상, 길이 8 이하인 문자열입니다.
*/

#include<iostream>
#include <string>
using namespace std;

bool solution(string s) {
    bool answer = false;
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i] <= '9') cnt++;
    }
    if((cnt == 4 || cnt == 6) && (s.length() == 4 || s.length() == 6)) answer = true;
    return answer;
}

int main()
{
    cout << solution("a123");
    return 0;
}