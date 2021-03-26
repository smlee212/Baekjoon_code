#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n;
int arr[500001];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int cnt = 0;
	int a = 0, b = n - 1;
	while (a < b) {
		arr[a]--;
		if (arr[a] == 0) a++;
		b--;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
