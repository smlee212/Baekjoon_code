#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int N;
vector <ll> v;

void sol(ll index, int cnt) {
	if (cnt > 10) return;
	v.push_back(index);
	for (int i = 0; i < 10; i++)
		if (index % 10 > i) sol(index * 10 + i, cnt + 1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < 10; i++) sol(i, 1); // i로 시작하는 감소하는 수를 찾는다.
	sort(v.begin(), v.end());
	ll res = (v.size() <= N) ? -1 : v[N];
	cout << res << endl;
	return 0;
}