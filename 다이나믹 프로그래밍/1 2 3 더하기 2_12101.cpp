#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int k = 0, m, n;
vector<int>v;

void dfs(int n) {
	if (n < 0) return;
	else if (n == 0) {
		k++;
		if (k == m) {
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << "+";
			}
			cout << v[v.size() - 1];
		}
		return;
	}
	else {
		v.push_back(1);
		dfs(n - 1);
		v.pop_back();

		v.push_back(2);
		dfs(n - 2);
		v.pop_back();

		v.push_back(3);
		dfs(n - 3);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	dfs(n);
	if (k < m) cout << "-1";
	return 0;
}