#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int num[8001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, max = 0;
	int a = 0, b, c, d;
	int min[2] = { 0, };
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		num[v[i] + 4000]++;
		a += v[i];
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < 8001; i++) {
		if (num[i] == 0) continue;
		if (num[i] > max) {
			max = num[i];
			min[0] = i - 4000;
			min[1] = 4001;
		}
		else if (num[i] == max && min[1] == 4001) {
			min[1] = i - 4000;
		}
	}

	a = round(a / double(N));
	cout << a << "\n";
	b = v[N/2];
	cout << b << "\n";
	c = (min[1] < 4001) ? min[1] : min[0];
	cout << c << "\n";
	d = v[N-1] - v[0];
	cout << d << "\n";
	
	return 0;
}
