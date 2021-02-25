#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int ls[100000];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int l = 0, r = 0, mid;
	for (int i = 0; i < n; i++) {
		cin >> ls[i];
		r += ls[i];
		l = max(l, ls[i]);
	}

	int res = r, sum = 0;

	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += ls[i];
			if (sum > mid) { // 더하면 초과되므로
				sum = ls[i]; // 새롭게 갱신해준다.
				cnt++;
			}
		}
		
		if (cnt <= m) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res << endl;

	return 0;
}