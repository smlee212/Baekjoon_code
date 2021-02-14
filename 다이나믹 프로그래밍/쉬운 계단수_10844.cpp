#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

#define MOD 1000000000
int d[2][12];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    int res = 9;
    for (int i = 2; i < 11; i++) 
    // 0~9 => 1~10까지로 변경한 것
    // 0, 11은 0->9, 9->0으로 변환된 것
        d[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        res = 0;
        for (int j = 1; j < 11; j++) {
          // d[i][0], d[i][11]은 작성되지 않기 때문에 신경쓰지 않아도 된다.
            d[i % 2][j] = (d[(i - 1) % 2][j - 1] + d[(i - 1) % 2][j + 1]) % MOD;
            res = (res + d[i % 2][j]) % MOD;
        }
    }
    cout << res << endl;
    return 0;
}