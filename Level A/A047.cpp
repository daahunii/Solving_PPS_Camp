/*
Baekjoon
<11721. 열 개씩 끊어 출력하기>

문제
알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다.
한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.
=======================================================================
입력
첫째 줄에 단어가 주어진다. 단어는 알파벳 소문자와 대문자로만 이루어져 있으며,
길이는 100을 넘지 않는다. 길이가 0인 단어는 주어지지 않는다.

출력
입력으로 주어진 단어를 열 개씩 끊어서 한 줄에 하나씩 출력한다.
단어의 길이가 10의 배수가 아닌 경우에는 마지막 줄에는 10개 미만의 글자만 출력할 수도 있다.
=======================================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> result;
    string N, subN;
    cin >> N;
    int cnt = 0;
    for(int i=0; i<N.size(); i++){
        subN += N[i];
        cnt++;  // 카운팅
        if(cnt%10 == 0){ // 10의 배수일 때 자르고 substring은 다시 초기화
            result.push_back(subN);
            subN.clear();
        }
        if(i == N.size()-1) result.push_back(subN); // 마지막에 담아놓은거 모두 담기
    }
    for(int i=0; i<result.size(); i++) cout << result[i] << endl;
    return 0;
}