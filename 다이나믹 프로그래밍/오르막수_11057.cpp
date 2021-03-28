#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, sum = 0;
int dp[1001][10] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) dp[i][j] += dp[i - 1][k];
			dp[i][j] %= 10007;
		}
	for (int i = 0; i < 10; i++) sum = (sum + dp[n][i]) % 10007;
	cout << sum % 10007 << endl;
	return 0;
}
