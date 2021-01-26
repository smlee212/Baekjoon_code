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
int n, m;
int graph[MAX][MAX];
bool visited[MAX];
int cnt = 0;

bool dfs(int x);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (dfs(i)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}

bool dfs(int x) {
    if (visited[x])
        return false;

    visited[x] = true;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[x][i]) {
            dfs(i);
        }
    }   
    return true;
}