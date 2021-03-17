#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n, s, r;
bool T[11];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s >> r;
	int data;
	for (int i = 0; i < s; i++) {
		cin >> data;
		T[data] = true;
	}
	for (int i = 0; i < r; i++) {
		cin >> data;
		v.push_back(data);
	}
	for (auto t : v) {
		if (t - 1 > 0 && T[t - 1]) {
			T[t - 1] = false;
		}
		else if (t + 1 <= n && T[t + 1]) {
			T[t + 1] = false;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 10; i++) {
		if (T[i]) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
