#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int cnt = 0, n;
vector<int> node[500001];
bool visited[500001];

void findleaf(int v, int depth) {
	int childnum = node[v].size();	
	if (v != 1 && childnum == 1) {
		if (depth % 2 == 1) cnt++;
		return;
	}

	for (int i = 0; i < childnum; i++) {
		if (visited[node[v][i]] == true) continue;
		visited[node[v][i]] = true;
		findleaf(node[v][i], depth + 1);
		visited[node[v][i]] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0, a, b; i < n-1; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	visited[1] = true;
	findleaf(1, 0);
	if (cnt % 2 == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}