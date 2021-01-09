#include<iostream>
using namespace std;

int function(int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int i = 665, cnt = 0;

	while(++i){
		if (function(i)) {
			cnt++;
			if (cnt == n) {
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}

int function(int x) {
	int count = 0;
	while (x) {
		if (x % 10 == 6) {
			count++;
			if (count == 3)
				return 1;
		}
		else {
			count = 0;
		}
		x = x / 10;
	}
	return 0;
}