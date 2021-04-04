#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, q, N, ice=0;
int A[64][64];
vector<int> L;
bool visited[64][64];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
// 격자를 2^L 크기의 부분 격자로 나눈다.
// 모든 부분 격자를 시계방향으로 90도 회전
// 인접한 얼음이 3개 미만일 때 1개 녹음

int Pow(int k) {
	int res = 1;
	while (k--) { res *= 2; }
	return res;
}

// 회전
void Rot(int x, int y, int len) {
	deque<deque<int>> subset(len);
	for (int i = x; i < x + len; i++) 
		for (int j = y, k = 0; j < y + len; j++, k++) 
			subset[k].push_front(A[i][j]);
	for (int i = x, k = 0; i < x + len; i++, k++)
		for (int j = y, s = 0; j < y + len; j++, s++)
			A[i][j] = subset[k][s];
}

void afterice() {
	vector<int> vx, vy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0) continue;
			int check = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && A[nx][ny] > 0) continue;
				check++;
			}
			if (check > 1) {
				vx.push_back(i);
				vy.push_back(j);
			}
		}
	}
	for (int i = 0; i < vx.size(); i++) A[vx[i]][vy[i]]--;
}


void FS(int Li) {
	// 부분 공간을 나눈 후
	int sub = Pow(Li);
	if (sub == 1) afterice();
	else {
		for (int i = 0; i < N; i += sub)
			for (int j = 0; j < N; j += sub)
				Rot(i, j, sub); // 회전시킨다
		afterice(); // 녹은 얼음 확인
	}
}

void bigice(int x, int y, int &cnt) { // 큰 덩어리의 얼음 개수
	visited[x][y] = true;
	cnt++;
	ice += A[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (A[nx][ny] == 0 || visited[nx][ny] == true) continue;

		bigice(nx, ny, cnt);
	}
}


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// 입력
	cin >> n >> q;
	N = Pow(n);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
	for (int i = 0, l; i < q; i++) {
		cin >> l; L.push_back(l);
	}
	for (int k = 0; k < L.size(); k++) FS(L[k]);

	// 큰 덩어리의 얼음 개수 세기
	int res = 0, numice = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0 || visited[i][j] == true) continue;
			bigice(i, j, numice);
			res = max(res, numice);
			numice = 0;
		}
	}
	cout << ice << endl << res << endl;
	return 0;
}