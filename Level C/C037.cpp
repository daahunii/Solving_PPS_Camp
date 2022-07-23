/*
Baekjoon
<6571. 피보나치 수의 개수>

문제
피보나치 수의 정의는 다음과 같다.
f1 := 1
f2 := 2
fn := fn-1 + fn-2 (n ≥ 3)
두 수 a와 b가 주어졌을 때, 구간 [a, b]에 포함되는 피보나치 수의 개수를 구하는 프로그램을 작성하시오.
=====================================================================================
입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 음이 아닌 두 정수 a와 b로 이루어져 있다.
입력의 마지막 줄에는 0이 두 개 주어진다. (a ≤ b ≤ 10^100) 두 수 a와 b는 불필요한 0으로 시작하지 않는다.

출력
각 테스트 케이스에 대해서, a ≤ fi ≤ b 인 피보나치 수 fi의 개수를 출력한다.
=====================================================================================
*/

// 첫번째 풀이는 작은 수는 다 되는데 큰 수를 넣으면 오버플로우가 발생하여 답을 못낸다. => 해결법은 문자열로 받아서 푸는거... (파이썬이면 순삭인데...ㅠ)
// #include <iostream>
// using namespace std;
// int fibonacci[1001] = {0,};
// void make_fibo(){
//     fibonacci[1] = 1;
//     fibonacci[2] = 2;
//     for(int i=3; i<1001; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
// }

// int main()
// {
//     int fibo_cnt = 0;
//     make_fibo();
//     while(true){
//         int a, b;
//         cin >> a >> b;
//         if(a == 0 && b == 0) break;

//         for(int i=0; i<1001; i++){
//             if(a <= fibonacci[i] && fibonacci[i] <= b) fibo_cnt++;
//         }
//         cout << fibo_cnt << endl;
//         fibo_cnt = 0;
//     }
//     return 0;
// }


// 큰 수(문자열) 처리 방법

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000;
string cache[MAX] = { "0", "1" };

string bigNumAdd(string num1, string num2){
    long long sum = 0;
    string result;

    while (!num1.empty() || !num2.empty() || sum){ //1의 자리부터 더하기 시작한다
        if (!num1.empty()){
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty()){
            sum += num2.back() - '0';
            num2.pop_back();
        }
        result.push_back((sum % 10) + '0'); //다시 string 형태로 만들어 push_back
        sum /= 10;
    }
    reverse(result.begin(), result.end()); //1의 자리부터 result에 넣었으므로 뒤집어줘야 한다
    return result;
}


//string 연산자 <= 오버로딩

bool operator<=(const string &a, const string &b){
    if (a.size() == b.size()){
        for (int i = 0; i < a.size(); i++){
            if (a[i] > b[i]) return false;
            else if (a[i] < b[i]) return true;
        }
        return true;
    }
    if (a.size() < b.size()) return true;
    else return false;
}

void preCalculate(void){
    for (int i = 2; i < MAX; i++) cache[i] = bigNumAdd(cache[i-1], cache[i-2]);
}

int main(void)
{
    preCalculate();
    while(true){
        string a, b;
        cin >> a >> b;
        
        if (a == "0" && b == "0") break;
        int cnt = 0;
        for (int i = 2; i < MAX; i++) if(a <= cache[i] && cache[i] <= b) cnt++;
        
        cout << cnt << "\n";
    }
    return 0;
}