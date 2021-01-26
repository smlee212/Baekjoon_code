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

#define MAX 50
int t;
int n, m, k;
int graph[MAX][MAX];


vector<int> res;

bool dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    cin >> t;
    int a, b;
    while(t--) {
        cin >> m >> n >> k;
        while(k--) { // 배추가 있는 곳 저장
            cin >> b >> a;
            graph[a][b] = 1;
        }

        int cnt = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j)) {
                    cnt++;
                }
            }
        }        
        cout << cnt << endl;
    }

    return 0;
}

bool dfs(int x, int y) { 
    
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }

    if (graph[x][y] == 1) {
        graph[x][y] = 0;

        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return true;
    }

    return false;
}