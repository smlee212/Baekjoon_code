#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n, m;
int s[50][50];

bool sol(int i, int j, int &start) {
	bool res = false;
	for (int k = start; i + k < n && j + k < m ; k++) {
		if (s[i][j] == s[i + k][j] && s[i][j] == s[i][j + k] && s[i][j] == s[i + k][j + k]) {
			start = k;
			res = true;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			s[i][j] = c - '0';
		}
	}
	int N = max(n, m);
	int start = 1;
	int tx = n - start, ty = m - start;
	bool check = false;
	for (int i = 0; i < tx; i++) {
		for (int j = 0; j < ty; j++) {
			if (start == N) break;
			if (sol(i, j, start)) {
				check = true;
				tx = n - start;
				ty = m - start;
			}
		}
	}
	start = (check == false) ? 0 : start;
	cout << pow(start+1, 2) << endl;
	return 0;
}
