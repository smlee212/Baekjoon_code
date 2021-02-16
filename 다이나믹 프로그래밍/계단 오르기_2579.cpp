#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 301
int n, res;
int arr[MAX];
int d[MAX];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    d[1] = arr[1];
    d[2] = arr[1] + arr[2];
    d[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for (int i = 4; i <= n; i++) {
        d[i] = max(d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]);
    }

    cout << d[n] << endl;
    return 0;
}