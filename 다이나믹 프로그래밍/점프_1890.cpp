#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;
int Map[101][101];
ll dp[101][101] = { 0, };
 
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> Map[i][j];
	
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i==n-1&&j==n-1){
				cout << dp[n - 1][n - 1] << endl;
				break;
			}
			if (dp[i][j] == 0) continue;
			int next = Map[i][j];
			if (i + next < n) {
				dp[i + next][j] += dp[i][j];
			}
			if (j + next < n) {
				dp[i][j + next] += dp[i][j];
			}
		}
	}
	return 0;
}