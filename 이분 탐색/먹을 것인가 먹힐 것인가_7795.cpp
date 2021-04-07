#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int t, n, m;
int A[20000], B[20000];
bool comp(int x, int y) { return x > y; }

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        int cnt = 0;
        cin >> n >> m;
        memset(A, 0, sizeof(int) * n);
        memset(B, 0, sizeof(int) * m);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];
        sort(A, A + n, comp);
        sort(B, B + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] > B[j]) cnt++;
                else break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}