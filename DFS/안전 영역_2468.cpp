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
#define HUN 100
int n;
int graph[MAX][MAX];
//bool visited[MAX];
int cnt = 0, res = 1, thr = 1, maxr = 0, cond;

bool dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] > maxr) {
                maxr = graph[i][j];
            }
        }
    }

    while (thr < maxr) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i,j)) {
                    cnt++;
                }
            }
        }        
        if (cnt > res) {
            res = cnt;
        }
        thr++;
    }

    cout << res << endl;

    return 0;
}

bool dfs(int x, int y) {    
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    }
    cond = HUN * (thr - 1);

    if (graph[x][y] > cond + thr && graph[x][y] <= cond + HUN) {
        graph[x][y] += HUN;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return true;
    }
    else if (graph[x][y] <= cond + HUN){
        graph[x][y] += HUN;
        return false;
    }
    else {
        return false;
    }
}