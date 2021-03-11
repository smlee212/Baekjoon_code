#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

char arr[201][201];
int R, C, N;
int dy[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void allInstall() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] = 'O';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> C >> N;
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') {
				q.push({ i,j });
			}
		}
	}
	bool flag = true;
	while (--N) {
		if (flag) {
			allInstall();
			flag = false;
			continue;
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			arr[x][y] = '.';
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dy[k][0];
				int ny = y + dy[k][1];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C || arr[nx][ny] == '.') continue;
				arr[nx][ny] = '.';
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] == 'O') {
					q.push({ i,j });
				}
			}
		}
		flag = true;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}