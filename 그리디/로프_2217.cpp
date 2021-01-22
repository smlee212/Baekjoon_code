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
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    int sum, maxW = 0;

    for (int i = n - 1; i >= 0; i--) {
        sum = w[i] * (n - i);
        if (sum > maxW) {
            maxW = sum;
        }
    }
    cout << maxW << endl;
    return 0;
}