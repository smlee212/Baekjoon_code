#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

string str;
stack<char> s;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> str;
	ll res = 0;
	int temp = 1;
	bool b = true;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
			b = false;
			break;
		}
		else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
			b = false;
			break;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				res += temp;
			}
			s.pop();
			temp /= 2;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				res += temp;
			}
			s.pop();
			temp /= 3;
		}
	}

	if (!b || !s.empty()) {
		cout << 0 << endl;
	}
	else {
		cout << res << endl;
	}

	return 0;
}