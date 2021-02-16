#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

char str1[1003], str2[1003];
int dp[2][1003];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin.getline(str1, 1001);
	cin.getline(str2, 1001);

	int len1 = strlen(str1), len2 = strlen(str2);

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1]) // 문자가 같다면
				dp[(i & 1)][j] = dp[!(i & 1)][j - 1] + 1;
			else
				dp[(i & 1)][j] = max(dp[!(i & 1)][j], dp[(i & 1)][j - 1]);
		}
	}
	cout << dp[(len1 & 1)][len2];

	return 0;
}