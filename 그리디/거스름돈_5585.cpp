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
    int n; cin >> n;
    int w[6] = {500, 100, 50, 10, 5, 1};
    int remain = 1000 - n;
    int cnt = 0;

    for (int i = 0; i < 6; i++) {        
        cnt += remain / w[i];
        remain %= w[i];    
    }
    cout << cnt << endl;

    return 0;
}