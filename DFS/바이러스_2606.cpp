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

#define MAX 101
int n, m;
int graph[MAX][MAX];
bool visited[MAX];
int cnt = 0;

void dfs(int x);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n >> m;
    int a, b;
    while(m--) {   
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    dfs(1);

    cout << cnt << endl;

    return 0;
}

void dfs(int x) { 
    visited[x] = true;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[x][i]) {
            cnt++;
            dfs(i);
        }
    }   
}