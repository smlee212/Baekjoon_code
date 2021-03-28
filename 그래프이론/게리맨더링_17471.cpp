#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, numP[11], adj[11][11], visted[11], sum, ans = 2e9;

int dfs(int x, int bm) {
	int res = numP[x];
	visted[x] = 1;
	for (int i = 0; i < n; ++i) {
		if (adj[x][i + 1] && (bm & (1 << i)) && !visted[i + 1])
			res += dfs(i + 1, bm);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> numP[i]; // 각 구의 인구수
	for (int i = 1, t; i <= n; ++i) {
		cin >> t;
		for (int j = 0, tmp; j < t; j++) {
			cin >> tmp;
			adj[i][tmp] = 1; // 연결된 구
		}
	}
	for (int i = 1, j; i < 1 << n; ++i) {
		memset(visted, 0, sizeof(visted));
		sum = 0;
		for (j = 0; j < n; ++j)
			if (i & (1 << j)) {
				sum = dfs(j + 1, i);
				break;
			}
		for (j = 0; j < n; ++j)
			if (~i & (1 << j)) {
				sum -= dfs(j + 1, ~i);
				break;
			}
		j = 1;
		while (j <= n && visted[j])j++;
		if (j > n) ans = min(ans, abs(sum));
	}
	cout << (ans == 2e9 ? -1 : ans);
	return 0;
}