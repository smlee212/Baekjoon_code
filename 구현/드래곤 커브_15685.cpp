#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int arr[101][101] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void sol(int x, int y, int d, int g) {
	deque<int> dq;
	arr[x][y] = 1;
	x += dx[d];
	y += dy[d];
	arr[x][y] = 1;
	dq.push_back(d);
	while (g--) {
		int dqsize = dq.size();
		int nd;
		for (int i = dqsize - 1; i >= 0; i--) {
			nd = (dq[i] + 1) % 4;
			dq.push_back(nd);
			x += dx[nd];
			y += dy[nd];
			arr[x][y] = 1;
		}
	}
}

int count_square() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x, y, d, g;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		sol(x, y, d, g);
	}
	cout << count_square() << endl;
	return 0;
}