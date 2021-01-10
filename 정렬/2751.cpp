#include<iostream>
using namespace std;

bool num[2000001] = { false };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, n;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> n;
		num[n + 1000000] = true;
	}

	for (int i = 0; i < 2000001; i++) {
		if(num[i]) cout << i - 1000000 << "\n";
	}
	
	return 0;
}
