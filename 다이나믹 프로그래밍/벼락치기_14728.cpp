#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, t, k, s;
int dp[10001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> t;
	while (n--) {
		cin >> k >> s;
		for (int i = t; i >= k; i--) {
			dp[i] = max(dp[i], dp[i - k] + s);
		}
	}
	cout << dp[t] << endl;
	return 0;
}