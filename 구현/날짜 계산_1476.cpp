#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int E, S, M;
	int res, y = 1;
	cin >> E >> S >> M;

	while (1) {
		if ((y - E) % 15 != 0) {
			y++;
			continue;
		}
		if ((y - S) % 28 != 0) {
			y++;
			continue;
		}
		if ((y - M) % 19 != 0) {
			y++;
			continue;
		}
		res = y;
		break;
	}
	cout << res << endl;
	return 0;
}