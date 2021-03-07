#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, m, h, res;
int visited[11][31] = { 0, };

bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start]) start++;
			else if (visited[j][start - 1]) start--;
		}
		if (start != i) return false;
	}
	return true;
}

void go(int here, int cnt) {
	if (cnt > 3) return;
	if (check()) {
		res = min(res, cnt); return;
	}
	for (int i = here; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

void sol() {
	go(1, 0);
	cout << ((res == 1e9) ? -1 : res) << endl;
}

void Input() {
	cin >> n >> m >> h;
	res = 1e9;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}
}

void solution() {
	Input();
	sol();
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solution();
	return 0;
}