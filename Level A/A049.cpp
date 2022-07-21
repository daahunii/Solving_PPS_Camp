/*
Baekjoon
<4659. 비밀번호 발음하기>

문제
좋은 패스워드를 만드는것은 어려운 일이다. 대부분의 사용자들은 buddy처럼 발음하기 좋고 기억하기 쉬운 패스워드를 원하나,
이런 패스워드들은 보안의 문제가 발생한다. 어떤 사이트들은 xvtpzyo 같은 비밀번호를 무작위로 부여해 주기도 하지만,
사용자들은 이를 외우는데 어려움을 느끼고 심지어는 포스트잇에 적어 컴퓨터에 붙여놓는다.
가장 이상적인 해결법은 '발음이 가능한' 패스워드를 만드는 것으로 적당히 외우기 쉬우면서도 안전하게 계정을 지킬 수 있다. 

회사 FnordCom은 그런 패스워드 생성기를 만들려고 계획중이다.
당신은 그 회사 품질 관리 부서의 직원으로 생성기를 테스트해보고 생성되는 패스워드의 품질을 평가하여야 한다. 높은 품질을 가진 비밀번호의 조건은 다음과 같다.

모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
이 규칙은 완벽하지 않다;우리에게 친숙하거나 발음이 쉬운 단어 중에서도 품질이 낮게 평가되는 경우가 많이 있다.
=======================================================================================================================
입력
입력은 여러개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 테스트할 패스워드가 주어진다.
마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다. 또한 패스워드는 대문자를 포함하지 않는다.

출력
각 테스트 케이스를 '예제 출력'의 형태에 기반하여 품질을 평가하여라.
=======================================================================================================================
*/

// #include <iostream>
// #include  <string>
// using namespace std;

// int main()
// {
//     int check1 = 0, check2 = 0, check3 = 0;
//     string word, vo = "aeiou";
//     while(true){
//         cin >> word;;
//         if(word == "end") break;
        
//         for(int i=0; i<vo.length(); i++){
//             if(word.find(vo[i]) == string::npos) check1 = 1; // 모음이 없는 경우 check = 1
//             else{ // 모음을 찾았다면 패스하고 검사 종료
//                 check1 = 0;
//                 break;
//             }
//         }
//         cout << check1 << " ";

//         for(int i=1; i<word.length()-1; i++){
//             int vo_cnt = 0, co_cnt = 0; // 모음, 자음 카운트
//             if(word[i-1] == 'a' || word[i-1] == 'e' || word[i-1] == 'i' || word[i-1] == 'o' || word[i-1] == 'u') vo_cnt++;
//             else co_cnt++;
//             if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') vo_cnt++;
//             else co_cnt++;
//             if(word[i+1] == 'a' || word[i+1] == 'e' || word[i+1] == 'i' || word[i+1] == 'o' || word[i+1] == 'u') vo_cnt++;
//             else co_cnt++;

//             if(vo_cnt == 3 || co_cnt == 3){
//                 check2 = 1;
//                 break;
//             }
//         }
//         cout << check2 << " ";

//         for(int i=0; i<word.length(); i++){
//             for(int j=0; j<i; j++){
//                 if(word[i] == word[j]){
//                     if(word[i] == 'e' || word[i] == 'o') continue;  // ee와 oo를 제외한 나머지 같은 글자 연속은 허용 x
//                     else{
//                         check3 = 1;
//                         break;
//                     }
//                 }
//             }
//             if(check3 == 1) break;
//         }
//         cout << check3 << endl;
//         if(check1 == 0 && check2 == 0 && check3 == 0) cout << "<" << word << ">" << " is acceptable." << endl;
//         else cout << "<" << word << ">" << " is not acceptable." << endl;
//     }
//     return 0;
// }

// 다른 풀이
#include <iostream>
#include <string>
using namespace std;

string input;
int cnt[30], lcnt, vcnt;
bool isVowel(int idx) {
	return ( idx==0 || idx==4 || idx==8 || idx==14 || idx==20 );
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while(1){
		cin >> input;
		if(input=="end") break;
		fill(cnt, cnt+30, 0);
		vcnt=0, lcnt=0;
		bool non_acceptable = false;
		for(int i = 0; i < input.size(); i++) {
			int idx = input[i]-'a';
			cnt[idx]++;
			
			if(isVowel(idx)) vcnt++, lcnt=0;
			else lcnt++, vcnt=0;
			if(lcnt==3 || vcnt==3){
				non_acceptable=true; break;	
			}  
			
			if(i >= 1) {
				if(input[i-1] == input[i] && (idx != 4 && idx != 14)){
					non_acceptable=true; break;	
				} 
			}	
		}
		
		if(cnt[0]==0 && cnt[4]==0 && cnt[8]==0 && cnt[14]==0 && cnt[20]==0) non_acceptable=true;	
		
		if(non_acceptable) cout << "<" << input << ">" << " is not acceptable.\n";
		else cout << "<" << input << ">" << " is acceptable.\n";
	}
	return 0;
}