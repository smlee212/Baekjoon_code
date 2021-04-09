#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;
int T[16], P[16];
int dp[17] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> T[i] >> P[i];

	for (int i = n; i >= 1; i--) {
		if (i + T[i] - 1 > n) {
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
	}
	cout << dp[1] << endl;
	return 0;
}