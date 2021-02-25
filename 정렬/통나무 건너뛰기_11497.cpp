#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> t(N);
		deque<int> ts;
		for (int i = 0; i < N; i++) {
			cin >> t[i];
		}
		sort(t.begin(), t.end());
		// 큰 값부터 좌우로 정렬해나간다.
		for (int i = N-1; i >= 0; i--) {
			if (i % 2) { 
				ts.push_back(t[i]);
			}
			else {
				ts.push_front(t[i]);
			}
		}
		// 첫 번째와 마지막은 연결되어 있으므로 추가해서 비교해준다.
		ts.push_back(ts[0]); 
		int MAX = 0;
		for (int i = 0; i < N; i++) {
			MAX = max(MAX, abs(ts[i] - ts[i + 1]));
		}
		cout << MAX << endl;
	}
	return 0;
}