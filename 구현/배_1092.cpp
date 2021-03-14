#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n, m;
int th[51];
vector<vector<int>> Box(50);

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> th[i];
	sort(th, th + n);
	cin >> m;
	int b;
	bool check;
	for (int j = 0; j < m; j++) {
		cin >> b;		
		if (b <= th[0]) {
			Box[0].push_back(b);
			continue;
		}
		check = false;
		for (int i = 1; i < n; i++) {
			if (b > th[i-1] && b <= th[i]) {
				Box[i].push_back(b);
				check = true;
				break;
			}
		}
		if (!check) {
			cout << -1 << endl;
			return 0;
		}
	}
	int box_cnt = 0, t = 0;
	while (box_cnt < m) {
		for (int i = 0; i < n; i++) {
			if (!Box[i].empty()) {
				Box[i].pop_back();
				box_cnt++;
			}
			else {
				for (int j = i - 1; j >= 0; j--) {
					if (!Box[j].empty()) {
						Box[j].pop_back();
						box_cnt++;
						break;
					}
				}
			}
		}
		t++;
	}
	cout << t << endl;
	return 0;
}