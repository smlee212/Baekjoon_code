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
int num[10] = { 0, };

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        int x = s[i] - '0';
        num[x]++;
    }
    int buf = (num[6] + num[9]);
    num[6] = buf / 2;
    if (buf % 2 == 1) {       
        num[9] = buf / 2 + 1;
    }
    else{
        num[9] = buf / 2;
    }
    int MAX = 0;
    for (int i = 0; i < 10; i++) {
        if (num[i] > MAX) {
            MAX = num[i];
        }
    }
    cout << MAX << endl;

    return 0;
}