#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(string a, string b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<string> str(N);
	string temp;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	sort(str.begin(), str.end(), comp);

	temp = str[0];
	cout << str[0] << "\n";
	for (int i = 1; i < N; i++) {
		if (temp == str[i]) continue;
		cout << str[i] << "\n";
		temp = str[i];
	}
	return 0;
}

bool comp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}