#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;
int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	dp[1] = 1;
	for (int t = 2; t <= n; t++) {
		int minnum = 1e9;
		for (int i = 1; i * i <= t; i++) {
			minnum = min(minnum, dp[t - i * i] + 1);
		}
		dp[t] = minnum;
	}
	cout << dp[n] << endl;
	return 0;
}