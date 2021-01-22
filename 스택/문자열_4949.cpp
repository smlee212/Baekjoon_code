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
    int ssize;
    bool res;
    while (1) {
        string s;
        getline(cin, s);

        stack<char> c;
        ssize = s.size();
        res = true;
        if (s[0] == '.') break;
        for (int i = 0; i < ssize; i++) {
            if (s[i] == '(' || s[i] == '[') {
                c.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!c.empty() && c.top() == '(') {
                    c.pop();
                }
                else {
                    res = false;
                    break;
                }
            }
            else if (s[i] == ']') {
                if (!c.empty() && c.top() == '[') {
                    c.pop();
                }
                else {
                    res = false;
                    break;
                }
            }
        }
        if (!c.empty() || !res) {
            cout << "no" << endl;
        }
        else {
            cout << "yes" << endl;
        }        
    }
    return 0;
}