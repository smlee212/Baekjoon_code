#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
using ll = long long;
#define endl '\n'
//int n;
//int m;
vector<int> num;
vector<char> cal;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
	string s; cin >> s;
	int buf = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			num.push_back(buf);
			cal.push_back(s[i]);
			buf = 0;
		}
		else {
			buf *= 10;
			buf += s[i] - '0';
		}
	}
	num.push_back(buf);
	
	int res = num[0];
	bool neg = false;
	for (int i = 0; i < cal.size(); i++) {
		if (cal[i] == '-') { // -인 경우
			if (neg) {
				res -= buf; 
			}
			neg = true;
			buf = num[i + 1];			
		}
		else { // +인 경우
			if (neg) {
				buf += num[i+1];
			}
			else {
				res += num[i+1];
			}
		}
	}
	if (neg) {
		res -= buf;
	}

	cout << res << endl;

    return 0;
}
