/*
Backjoon
<2606. 바이러스>


예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 
1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 
전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 
1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

===========================================================================================
입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 
네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

(bfs(queue)나 dfs(stack)로 접근하면 될 것 같다.)
===========================================================================================
*/

#include <iostream>
#include <queue>
using namespace std;
int map[101][101] = {0,}; //컴퓨터 연결 쌍 저장
int computer_num; // 컴퓨터 수(노드 개수)
bool visit[101] = {false,}; // 방문 여부
int virus; //1번 컴퓨터를 통해 바이러스에 걸리게 되는 컴퓨터 수

void DFS(int com_num){
    visit[com_num] = true; // 방문 체크

    for(int i=1; i<=computer_num; i++){
        if(!visit[i] && map[com_num][i] == 1){ // 방문하지 않았고 연결된 노드가 존재하면
            virus++; // 감염시키고 다음 노드로...
            DFS(i);
        }
    }
}

void BFS(int com_num){
    visit[com_num] = true; // 방문 체크
    queue<int> q;
    q.push(com_num);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=1; i<=computer_num; i++){
            if(!visit[i] && map[node][i] == 1){
                q.push(i); // queue에 삽입
                visit[i] = true; // 방문 체크
                virus++;
            }
        }
    }
}

int main(){
    int pair_num; // 연결 쌍 개수(엣지 개수)
    cin >> computer_num;
    cin >> pair_num;

    for(int i=0; i<pair_num; i++){ // map으로 쌍 저장
        int com1, com2;
        cin >> com1 >> com2;
        map[com1][com2] = map[com2][com1] = 1;
    }

    // DFS(1); // 1번 컴퓨터
    BFS(1); // 1번 컴퓨터
    cout << virus << endl;
}
