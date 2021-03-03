#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 100001
int N, resA, resB;
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int l = 0, r = N - 1;
	int min_dif = abs(arr[l] + arr[r]);
	resA = arr[l]; resB = arr[r];
	while (l < r) {
		int dif = arr[l] + arr[r];
		if (abs(dif) < min_dif) {
			min_dif = abs(dif);
			resA = arr[l]; resB = arr[r];
		}
		if (dif == 0) break;
		else if (dif < 0) l++;
		else r--;
	}
	cout << resA << " " << resB << endl;
	return 0;
}