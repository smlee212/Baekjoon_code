#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n, m;
int res = 64;
int Map[8][8];

// 동, 북, 서, 남
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

deque<pair<int, int>> dq;

void Map_copy(int a[8][8], int b[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void Cam_sol(int nx, int ny, int t) {
	while (nx < n && ny < m && nx >= 0 && ny >= 0) {
		if (Map[nx][ny] == 6) return;
		if (Map[nx][ny] == 0) {
			Map[nx][ny] = -1;
		}
		nx += dx[t];
		ny += dy[t];
	}
}

void DFS(int index) {
	if (index == dq.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (Map[i][j] == 0) cnt++;
			}
		}
		res = min(res, cnt);
		return;
	}
	int x = dq[index].first;
	int y = dq[index].second;
	int cam = Map[x][y];
	int Map_backup[8][8];

	// 해당 카메라의 감시 구역 확인하기
	int nx, ny;
	for (int t = 0; t < 4; t++) {
		// Map 백업
		Map_copy(Map_backup, Map);

		// 우 감시 (1, 2, 3, 4, 5)
		Cam_sol(x + dx[t], y + dy[t], t);

		// 좌 감시 (2, 4, 5)
		if (cam != 1 && cam != 3) {
			int tt = (t + 2) % 4;
			Cam_sol(x + dx[tt], y + dy[tt], tt);
		}

		// 상 감시 (3, 4, 5)
		if (cam > 2) {
			int tt = (t + 1) % 4;
			Cam_sol(x + dx[tt], y + dy[tt], tt);
		}

		// 하 감시 (5)
		if (cam == 5) {
			int tt = (t + 3) % 4;
			Cam_sol(x + dx[tt], y + dy[tt], tt);
		}

		// 다음 카메라에 대해 진행
		DFS(index + 1);

		// 복원
		Map_copy(Map, Map_backup);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	pair<int, int> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Map[i][j];
			if (Map[i][j] > 0 && Map[i][j] < 6) {
				p.first = i;
				p.second = j;
				dq.push_back(p);
			}
		}
	}
	DFS(0);
	cout << res << endl;
	return 0;
}