#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll n, k;

ll sol(ll mid) {
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        // 각 행에서 mid까지 만들수 있는 개수를 계산한다.
        // 각 행마다 n개까지 있으므로 n개 또는 mid / i 중 작은 것을 선택
        cnt += min(n, mid / i); 
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;

    ll l = 1, r = n * n; // 1부터 n제곱 까지
    ll mid;
    ll res = 1;

    while (l <= r) {
        mid = (l + r) / 2;

        if (sol(mid) >= k) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << endl; 

    return 0;
}