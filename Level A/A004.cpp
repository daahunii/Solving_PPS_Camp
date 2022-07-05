/*
Programmers
<나누어 떨어지는 숫자 배열>

array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.

제한사항
arr은 자연수를 담은 배열입니다.
정수 i, j에 대해 i ≠ j 이면 arr[i] ≠ arr[j] 입니다.
divisor는 자연수입니다.
array는 길이 1 이상인 배열입니다.

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] % divisor == 0) answer.push_back(arr[i]);
        else continue;
    }
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    int a[]={6, 2, 3, 9, 4, 8, 11};
    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));
    vector<int> v = solution(d, 3);
    
    cout << "[";
    for(int i=0; i<v.size(); i++){
        cout << v[i];
        if(v.size() != 1 && i < v.size()-1) cout << ","; // 배열에 숫자 하나이면 콤마 출력 x
    }
    cout << "]";
}