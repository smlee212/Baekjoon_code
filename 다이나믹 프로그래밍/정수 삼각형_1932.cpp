#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 501
int n, res;
int buf[MAX] = { 0, };
int d[MAX] = { 0, };

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    int data;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> data;
            buf[j] = max(d[j - 1], d[j]) + data;
        }
        for (int j = 1; j <= i; j++) {
            d[j] = buf[j];
        }
    }

    res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, d[i]);
    }

    cout << res << endl;

    return 0;
}