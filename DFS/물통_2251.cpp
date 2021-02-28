#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 201
int A, B, C;
bool visited[MAX][MAX][MAX] = { 0, };
vector<int> v;

void sol() {
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(0, 0), C));

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visited[a][b][c] == true) continue;
        visited[a][b][c] = true;

		if (a == 0) v.push_back(c); // 값을 저장

        // 6가지 경우에 대해 비교

        // A물통에서 B물통으로 줄 때
        if (a + b > B) q.push(make_pair(make_pair(a + b - B, B), c));
        else q.push(make_pair(make_pair(0, a + b), c));

        // A물통에서 C물통으로 줄 때
        if (a + c > C) q.push(make_pair(make_pair(a + c - C, b), C));
        else q.push(make_pair(make_pair(0, b), a + c));

        // B물통에서 A물통으로 줄 때
        if (b + a > A) q.push(make_pair(make_pair(A, b + a - A), c));
        else q.push(make_pair(make_pair(b + a, 0), c));

        // B물통에서 C물통으로 줄 때
        if (b + c > C) q.push(make_pair(make_pair(a, b + c - C), C));
        else q.push(make_pair(make_pair(a, 0), b + c));

        // C물통에서 A물통으로 줄 때
        if (c + a > A) q.push(make_pair(make_pair(A, b), c + a - A));
        else q.push(make_pair(make_pair(c + a, b), 0));

        // C물통에서 B물통으로 줄 때
        if (c + b > B) q.push(make_pair(make_pair(a, B), c + b - B));
        else q.push(make_pair(make_pair(a, b + c), 0));
	}

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> A >> B >> C;
    sol();
	return 0;
}