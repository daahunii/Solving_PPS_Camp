/*
Baekjoon
<17211. 좋은 날 싫은 날>

문제
지은이가 건국한 나라인 유애나에 살고 있는 재현이는 너무 단순한 나머지 매일이 기분이 좋은 날, 기분이 싫은 날 두가지로 나누어진다. 
어느 날 지은이는 재현이에 대한 놀라운 사실을 발견했다! 재현이의 오늘의 기분이 내일의 기분에 영향을 준다는 것이었다. 
문득 지은이는 N일 뒤의 재현이의 기분이 어떻게 될지 궁금하였다. 
지은이를 위해 N일 뒤 재현이의 기분이 어떨지 알려주는 프로그램을 만들어보자.
===================================================================================================
입력
첫째 줄에 정수 N(1 ≤ N ≤ 100)과 현재 재현이의 기분(좋은 날 0, 싫은 날 1)이 주어진다.

둘째 줄에 차례대로 재현이가 기분이 좋은 날의 다음 날도 기분이 좋은 날일 확률,
다음 날은 기분이 싫은 날일 확률, 기분이 싫은 날의 다음 날이 기분이 좋은 날일 확률,
다음 날도 기분이 싫은 날일 확률이 주어진다. 확률은 소수점 둘째자리까지 주어진다.

출력
N일 뒤의 재현이의 기분이 좋은 날일 확률과 싫은 날일 확률에 1,000을 곱해
소수점 첫째자리에서 반올림한 수를 차례대로 출력한다. 절대 오차는 100까지 허용한다.

N번째 날 Good = (n-1)번째 날 좋은 날 확률 * gg + (n-1)번째 날 싫은 날 확률 * bg
N번째 날 Bad = (n-1)번째 날 싫은 날 확률 * gb + (n-1)번째 날 좋은 날 확률 * bb
===================================================================================================
*/

// #include <iostream>
// using namespace std;

// int main()
// {
//     int N, feel; // N일 뒤 기분, 기분(0: 좋은 날, 1: 싫은 날)
//     double gg, gb, bg, bb, p, q;
//     cin >> N >> feel;
//     cin >> gg >> gb >> bg >> bb;
//     if(feel == 1) q = 1.0;
//     else p = 1.0;

//     for(int i=0; i<N; i++){
//         double x = gg*p + bg*q; // N번째 날 Good = (n-1)번째 날 좋은 날 확률 * gg + (n-1)번째 날 싫은 날 확률 * bg
//         double y = gb*p + bb*q; // N번째 날 Bad = (n-1)번째 날 싫은 날 확률 * gb + (n-1)번째 날 좋은 날 확률 * bb
//         p = x, q = y;
//     }
//     cout << 1000*p << endl;
//     cout << 1000*q << endl;
//     return 0;
// }

#include <stdio.h>
double gg, gb, bg, bb, p, q;
int main()
{
    int N, feel; // N일 뒤 기분, 기분(0: 좋은 날, 1: 싫은 날)
    scanf("%d %d", &N, &feel);
    scanf("%lf %lf %lf %lf", &gg, &gb, &bg, &bb);
    if(feel == 1) q = 1.0;
    else p = 1.0;
    
    for(int i=0; i<N; i++){
        double x = gg*p + bg*q;
        double y = gb*p + bb*q;
        p = x, q = y;
    }
    printf("%d\n%d", (int)(1000*p), (int)(1000*q));
    return 0;
}