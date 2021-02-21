#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 1000000
int n, m;
int res = 0;
int h[MAX]; 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int l = 0, r = 0, mid;
	long long sum;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		r = max(r, h[i]);
	}
	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += max(h[i] - mid, 0);
		}
		if (sum == m) {
			res = mid;
			break;
		}
		else if (sum > m){
			l = mid + 1;
			res = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res << endl;
	return 0;
}