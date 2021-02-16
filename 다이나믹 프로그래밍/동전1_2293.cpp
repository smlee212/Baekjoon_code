#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, k;
int dp[10001] = { 1 };

/*
 * idx 0   1   2   3   4   5   6   7   8   9   10  (k)
 * dp  1   0   0   0   0   0   0   0   0   0   0   (초기화)
 * dp  1   1   1   1   1   1   1   1   1   1   1   (1만 사용하여 k를 만들 수 있는 경우의 수)
 * dp  1   1   2   2   3   3   4   4   5   5   6   (1과 2를 사용하여 k를 만들 수 있는 경우의 수)
 * dp  1   1   2   2   3   4   5   6   7   8   10  (1, 2, 5를 모두 사용하여 k를 만들 수 있는 경우의 수)
 *
 * 5원 = 0원 + 5원 (coins[i] = 5일때)
 * 5원 = 3원 + 2원 (coins[i] = 2일때)
 * 5원 = 4원 + 1원 (coins[i] = 1일때)
 * ...
 *
 * dp[j] = dp[j](기존의 동전 종류를 이용해 k를 만드는 경우의 수)
 *         + dp[j - coins[i]](새 동전 종류 사용하는 경우 추가)
 *
 */

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int coins;
    for (int i = 0; i < n; i++) {
        cin >> coins;
        for (int j = coins; j <= k; j++) {
            dp[j] += dp[j - coins];
        }
    }
    cout << dp[k] << endl;
	return 0;
}
