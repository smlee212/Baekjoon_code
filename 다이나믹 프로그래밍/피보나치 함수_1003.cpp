#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int tc, n, a = 0, b = 0;
int d0[41], d1[41];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> tc;
    
    d0[0] = 1;
    d0[1] = 0;

    d1[0] = 0;
    d1[1] = 1;

    while (tc--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            d0[i] = d0[i - 1] + d0[i - 2];
            d1[i] = d1[i - 1] + d1[i - 2];
        }
        cout << d0[n] << ' ' << d1[n] << endl;
    }
    

    return 0;
}