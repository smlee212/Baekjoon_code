#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int tc, n;
int d[11];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> tc;
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    while (tc--) {
        cin >> n;
        for (int i = 4; i <= n; i++) {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        cout << d[n] << endl;
    }
    

    return 0;
}