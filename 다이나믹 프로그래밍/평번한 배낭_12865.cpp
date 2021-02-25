#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int dp[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, w, v;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w >> v;
		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k] << endl;
	return 0;
}