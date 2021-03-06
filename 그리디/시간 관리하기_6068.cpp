#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

#define MAX 1001
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)
int n;
int T[MAX], S[MAX];

void q(int left, int right)
{
	int pl = left;
	int pr = right;
	int x = S[(pl + pr) / 2];

	do {
		while (S[pl] < x) pl++;

		while (S[pr] > x) pr--;

		if (pl <= pr) {
			swap(int, S[pl], S[pr]);
			swap(int, T[pl], T[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) q(left, pr);

	if (pl < right) q(pl, right);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tsum = 0, smax = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> S[i];
		tsum += T[i];
		smax = max(smax, S[i]);
	}
	int t = smax;
	int res = 0;	
	if (smax < tsum) {
		res = -1;
	}
	else {
		q(0, n - 1);
		for (int i = n - 1; i >= 0; i--) {
			if (t > S[i]) {
				t = S[i];
			}
			t -= T[i];
		}
		if (t > 0) res = t;
		else res = -1;
	}
	cout << res << endl;
	return 0;
}