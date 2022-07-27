/*
Baekjoon
<1260. DFS와 BFS>

문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
==============================================================================================
입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
==============================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int N, M, S;
vector<int> adjList[1001];
bool isVisited[1001] = {false,};
stack<int> st;
queue<int> que;

/* 재귀 함수를 이용한 dfs */
void dfs(int V) {
    if (isVisited[V]) return; // 이미 방문했다면 return
    isVisited[V] = true;
    cout << V << " ";
    
    for (int i=0; i<adjList[V].size(); i++) { // 인접 노드 재귀함수 호출
        int next = adjList[V][i];
        dfs(next);
    }
}

/* stack을 이용한 dfs */
// void dfs2(int V) {
//     st.push(V); // 루트 노드 삽입
    
//     while (!st.empty()) {
//         int cur = st.top();
//         st.pop();
        
//         if (isVisited[cur]) { continue; }
//         isVisited[cur] = true;
//         cout << cur << " ";
//         // 숫자가 작은 노드 먼저 방문하기 위해 reverse
//         for (int i=adjList[cur].size()-1; i>=0; i--) { 
//             int next = adjList[cur][i];
//             st.push(next);
//         }
//     }
// }

void bfs(int V) {
    que.push(V); // 루트 노드 삽입
    
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        
        if (isVisited[cur]) { continue; }
        isVisited[cur] = true;
        
        cout << cur << " ";
        
        for (int i=0; i<adjList[cur].size(); i++) { // 인접 노드들 삽입
            int next = adjList[cur][i];
            que.push(next);
        }
    }
}

int main() {
    cin >> N >> M >> S; // 노드 수: N, 간선 수: M, 시작 노드: S
    
    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }

    for (int i=0; i<1001; i++) sort(adjList[i].begin(), adjList[i].end());
    
    fill_n(isVisited, 1001, false); // 방문 여부 초기화
    dfs(S);  

    // fill_n(isVisited, 1001, false); // 방문 여부 초기화
    // dfs2(S);
    cout << endl;
    fill_n(isVisited, 1001, false);
    bfs(S);
    return 0;
}
