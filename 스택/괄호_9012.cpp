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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ssize; cin >> n;
    bool res;
    for (int i = 0; i < n; i++) {
        string s;
        stack<char> c;
        res = true;
        cin >> s;
        ssize = s.size();
        for (int j = 0; j < ssize; j++) {            
            if (s[j] == '(') {
                c.push(s[j]);
            }
            else if (!c.empty() && c.top() == '(' && s[j] == ')') {
                c.pop();
            }
            else {
                res = false;
                break;
            }
        }
        if (!c.empty() || !res) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}