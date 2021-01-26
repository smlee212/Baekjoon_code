#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
#define endl '\n'
using ll = long long;
//////////////////////////////

#define MAX 1001
int n, m ,v;
bool visited_dfs[MAX];
bool visited_bfs[MAX];
int graph[MAX][MAX];

void dfs(int start);
void bfs(int start);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    cin >> n >> m >> v;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }
    dfs(v);
    cout << endl;
    bfs(v);

    return 0;
}

void dfs(int start) { // stack과 재귀함수
    visited_dfs[start] = true; // 방문 확인
    cout << start << ' '; // 출력하고

    for (int next = 1; next <= n; next++) { // start와 연결된 노드를 찾는다.
        if (!visited_dfs[next] && graph[start][next]) { // 연결된 다음노드가 방문하지 않았다면
            dfs(next); // 방문하러 간다.
        }
    }
}

void bfs(int start) { // queue
    deque<int> dq;
    dq.push_back(start);
    visited_bfs[start] = true;

    while (!dq.empty()) {
        int now = dq.front();
        dq.pop_front();
        cout << now << ' ';
        for (int next = 1; next <= n; next++) { // now와 연결된 모든 노드를 찾는다.
            if (!visited_bfs[next] && graph[now][next]) { // 연결이 되어 있고, 방문하지 않았다면
                dq.push_back(next); // next를 queue에 넣는다.
                visited_bfs[next] = true; // 방문 확인
            }
        }
    }
}