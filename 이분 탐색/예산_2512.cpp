#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 10000
int n, m; // N은 3 이상 10,000 이하이다
int res = 0;
int arr[MAX];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int l = 0, r = 0, mid;
	long long sum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r = max(arr[i], r);
	}
	cin >> m;
	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += min(mid, arr[i]);
		}
		if (sum == m) {
			res = mid;
			break;
		}
		else if (sum > m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			res = mid;
		}
	}
	cout << res << endl;
	return 0;
}