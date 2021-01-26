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
//int n, m;
int w, h;
int graph[MAX][MAX];
//bool visited[MAX];
int cnt;

bool dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> w >> h;
    int a, b;
    while (w != 0 && h != 0) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {                
                cin >> graph[i][j];
            }
        }
        cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dfs(i, j))
                    cnt++;
            }
        }
        cout << cnt << endl;

        cin >> w >> h;
    }

    return 0;
}

bool dfs(int x, int y) {    
    if (x < 0 || y < 0 || x >= h || y >= w) {
        return false;
    }

    if (graph[x][y]) {
        graph[x][y] = 0;

        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        dfs(x + 1, y + 1);
        dfs(x + 1, y - 1);
        dfs(x - 1, y + 1);
        dfs(x - 1, y - 1);
        return true;
    }
    else {
        return false;
    }
}