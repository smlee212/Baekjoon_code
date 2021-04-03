#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, a, b, m;
int res = 0;
vector<int> tree[101];
bool visited[101];

void findab(int src, int cnt) {
	if (src == b) {
		res = cnt;
		return;
	}
	int nodesize = tree[src].size();
	for (int i = 0; i < nodesize; i++) {
		int dst = tree[src][i];
		if (visited[dst] == true) continue;
		visited[dst] = true;
		findab(dst, cnt+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> m;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	visited[a] = true;
	findab(a, 0);
	cout << ((res == 0) ? -1 : res) << endl;
	return 0;
}