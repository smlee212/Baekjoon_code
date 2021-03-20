#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;
int cnt = 0, Max = 0;
int menu[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int num;
	for (int i = 0; i < 2 * n; i++) {
		cin >> num;
		menu[num]++;
		if (menu[num] == 1) {
			cnt++;
		}
		else if (menu[num] == 2) {
			cnt--;
		}
		Max = max(cnt, Max);
	}
	cout << Max << endl;
	return 0;
}
