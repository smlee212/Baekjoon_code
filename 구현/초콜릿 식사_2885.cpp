#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int k;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k;
	int l = 0;
	for (l; pow(2, l) < k; l++);
	int minlen = pow(2, l);
	if (minlen == k) {
		cout << minlen << ' ' << 0 << endl;
		return 0;
	}
	cout << minlen << ' ';
	int cnt = 0, buflen;
	while (k > 0) {
		buflen = minlen / 2;
		if (buflen <= k) {
			k -= buflen;
		}
		minlen = buflen;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}