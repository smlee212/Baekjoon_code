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

#define MAX 25
int n;
int graph[MAX][MAX];
int num = 2;
int cnt = 0;

vector<int> res;

bool dfs(int x, int y);

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j)) {
                res.push_back(cnt);
                num++;
                cnt = 0;
            }
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", num-2);
    for (unsigned int i = 0; i < res.size(); i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}

bool dfs(int x, int y) { // stack과 재귀함수
    
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    }

    if (graph[x][y] == 1) {
        graph[x][y] = num;
        cnt++;

        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        return true;
    }

    return false;
}