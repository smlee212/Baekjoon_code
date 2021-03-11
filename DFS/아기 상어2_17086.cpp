#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 50
int n, m;
int Map[MAX][MAX];
int cnt_1 = 0, res = 0;
int dx[8] = { -1, 0, 1, -1, 1, -1, 0 ,1 };
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };

void DFS(int d, int cnt) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j] != d - 1) continue;
			for (int k = 0; k < 8; k++) {
				if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m && Map[i + dx[k]][j + dy[k]] == 0) {
					Map[i + dx[k]][j + dy[k]] = d;
					cnt++;
				}
			}
		}
	}
	if (cnt == n * m - cnt_1) {
		res = d - 1;
		return;
	}
	else {
		DFS(d + 1, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) cnt_1++;
		}
	}
	DFS(2, 0);
	cout << res << endl;
	return 0;
}