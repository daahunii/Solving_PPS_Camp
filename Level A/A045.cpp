/*
Baekjoon
<1157. 단어 공부>

문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
단, 대문자와 소문자를 구분하지 않는다.
=========================================================================================
입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
=========================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int alpha[26] = {0,};
    string word, lower_w;
    cin >> word;
    for(int i=0; i<word.length(); i++){
        if(word[i] >= 'A' && word[i] <= 'Z') lower_w += (word[i]+32);
        else lower_w += word[i];
    }
    for(int i=0; i<lower_w.size(); i++){
        alpha[(int)(lower_w[i]-'a')]++;
    }
    int max = 0, max_idx;
    for(int i=0; i<sizeof(alpha)/sizeof(int); i++){ // 많이 쓰인 알파벳 찾기
        if(alpha[i] >= max){
            max = alpha[i];
            max_idx = i;
        }
    }
    int cnt = 0;
    for(int i=0; i<sizeof(alpha)/sizeof(int); i++){
        if(max == alpha[i]) cnt++;
        if(cnt >= 2){   // 많이 쓰인 알파벳이 여러 개이면
            cout << "?";
            return 0;
        }
    }
    char result = 'A' + max_idx;
    cout << result;
    return 0;
}