/*
Programmers
<JadenCase 문자열 만들기>

문제 설명

JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.
단, 첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다. (첫 번째 입출력 예 참고)
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

제한 조건
s는 길이 1 이상 200 이하인 문자열입니다.
s는 알파벳과 숫자, 공백문자(" ")로 이루어져 있습니다.
숫자는 단어의 첫 문자로만 나옵니다.
숫자로만 이루어진 단어는 없습니다.
공백문자가 연속해서 나올 수 있습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> split(string str, char Delimiter); // c++에는 split 함수가 없음..

string solution(string s) {
    string answer = "";
    vector<string> split_str = split(s, ' ');

    for(int i=0; i<split_str.size(); i++){
        for(int j=0; j<split_str[i].length(); j++){
            string word = split_str[i];
            if(j == 0){
                if(word[j]>='a' && word[j] <= 'z') word[j] -= 32;
            }
            else if(j > 0){
                if(word[j]>='A' && word[j] <= 'Z') word[j] += 32;
            }
            split_str[i] = word;
        }
    }
    for(int i=0; i<split_str.size(); i++){
        answer += split_str[i];
        if(i < split_str.size()-1) answer += " ";
    }
    return answer;
}

int main()
{
    string result = solution("3people unFollowed me");
    cout << result << endl;
    return 0;
}

vector<string> split(string str, char Delimiter){
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
    vector<string> result;
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
    return result;
}