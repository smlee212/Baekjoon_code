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

#define MAX 20
//int n, m, k;
int R, C;
char graph[MAX][MAX]; 
bool visited[26]; // 알파벳
int res;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int Bigger(int a, int b) { return (a > b) ? a : b; }
bool dfs(int x, int y, int cnt);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> R >> C; // 세로 R, 가로 C
    // 상하좌우 이동 가능, 지금까지 지나온 알파벳과 중복되는 것이 있으면 안됨
    // 좌측 상단에서 시작하여 최대 몇칸까지 움직일 수 있는가? 좌측 상단 포함
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    }
    
    visited[graph[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << res << endl;

    return 0;
}

bool dfs(int x, int y, int cnt) {    
    res = Bigger(res, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];     

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) { // 다음 이동한 칸이 유효하고
            int alpabet = graph[nx][ny] - 'A';
            if (visited[alpabet] == false) { // 방문하지 않았다면
                visited[alpabet] = true;
                dfs(nx, ny, cnt + 1); // 다음 칸을 방문
                visited[alpabet] = false;
            }
        }
    }    
    return false;
}