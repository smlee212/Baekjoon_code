#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, m;
int a[50][50], b[50][50];

void a_change(int x, int y) {
	for (int i = x; i <= x + 2; i++) 
		for (int j = y; j <= y + 2; j++)
			a[i][j] = 1 - a[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = s[j] - '0';
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			b[i][j] = s[j] - '0';
	}
	int cnt = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
			if (a[i][j] != b[i][j]) {
				a_change(i, j);
				cnt++;
			}
	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j]) {
				cnt = -1;
				check = false;
				break;
			}
		if (!check) break;
	}
	cout << cnt << endl;
	return 0;
}