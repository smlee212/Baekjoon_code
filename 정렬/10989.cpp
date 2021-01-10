#include<iostream>
using namespace std;

int num[10001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		num[x]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (num[i] == 0) continue;
		for (int j = 0; j < num[i]; j++) {
			cout << i << "\n";
		}		
	}
	
	return 0;
}
