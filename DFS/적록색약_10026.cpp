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

#define MAX 100
int n;
char graph[MAX][MAX]; 
int visited[MAX][MAX] = { 0, };
int cnt = 0, res, thr = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

bool dfs(int x, int y, char color, int mode);
bool vaild(int x, int y);
bool visit(int x, int y);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j, graph[i][j], 1)) {
                cnt++;
            }
        }
    }
    cout << cnt << ' ';
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j, graph[i][j], 2)) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

bool dfs(int x, int y, char color, int mode) {       
    if (mode == 1) {
        if (!vaild(x, y)) return false; // 유효한 자리인지 확인

        if (visit(x, y)) return false; // 방문한 적이 있는지 확인

        if (graph[x][y] == color) {
            visited[x][y] = 1; // B G R 순서로 저장됨

            dfs(x + 1, y, color, 1);
            dfs(x - 1, y, color, 1);
            dfs(x, y + 1, color, 1);
            dfs(x, y - 1, color, 1);
            return true;
        }
        return false;
    }
    else {
        if (!vaild(x, y)) return false; // 유효한 자리인지 확인

        if (!visit(x, y)) return false; // 방문한 적이 있는지 확인

        if ((graph[x][y] == color) || (graph[x][y] != 'B' && color != 'B')) {
            visited[x][y] = 0;

            dfs(x + 1, y, color, 2);
            dfs(x - 1, y, color, 2);
            dfs(x, y + 1, color, 2);
            dfs(x, y - 1, color, 2);
            return true;
        }
        return false;
    }
}

bool vaild(int x, int y) {
    return (x >= 0 && x < n&& y >= 0 && y < n) ? true : false;
}

bool visit(int x, int y) {
    return (visited[x][y] > 0) ? true : false;
}