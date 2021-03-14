#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll n, m;
int T[100001];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> T[i];
	ll res = 0, cnt_human = 0, Left = 0, Right, Mid;
	Right = *max_element(T, T + n) * (ll)m; // 가장 오래 걸리는 심사대 시간 * 인원수
	while (Left <= Right) { // 해당 시간동안 몇명을 심사하는지 확인
		Mid = (Left + Right) / 2;
		for (int i = 0; i < n; i++) cnt_human += Mid / T[i];
		if (m <= cnt_human) {
			res = Mid;
			Right = Mid - 1;
		}
		else Left = Mid + 1;
		cnt_human = 0;
	}
	cout << res << endl;
	return 0;
}