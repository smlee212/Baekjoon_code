#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int arr[1000000];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int s, c; cin >> s >> c;
	int MaxL = 0, MinL = 1e9;
	ll sum = 0;
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
		MaxL = max(MaxL, arr[i]);
		sum += arr[i];
	}
	ll l = 1, r = MaxL, res = 0, mid;
	int cnt;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;

		for (int i = 0; i < s; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt < c) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			res = mid;
		}
	}
	
	cout << sum - res * c << endl;
	return 0;
}