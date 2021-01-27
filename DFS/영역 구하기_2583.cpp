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
int n, m, k;
int graph[MAX][MAX] = { 0, };
vector<int> res;
int cnt = 0;

bool dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> m >> n >> k;
    int x1, x2, y1, y2;

    while (k--) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int j = y1; j < y2; j++) {
            for (int i = x1; i < x2; i++) {
                graph[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (graph[i][j] == 0) {
                dfs(i, j);
                res.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(res.begin(), res.end());
    int vsize = res.size();
    cout << vsize << endl;
    for (int i = 0; i < vsize; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;

    return 0;
}

bool dfs(int x, int y) {    
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }

    if (graph[x][y] != 0) {
        return false;
    }
    else {
        cnt++;
        graph[x][y] = -1;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return true;
    }
}