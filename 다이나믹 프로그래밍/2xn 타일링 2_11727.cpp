#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    int d[1001] = { 0, }; d[0] = 0, d[1] = 1, d[2] = 3;
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 1] + (d[i - 2] << 1)) % 10007;
    }
    cout << d[n] << endl;
    return 0;
}