#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 10001
int n;
int arr[MAX], d[MAX] = { 0, };


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    if (n >= 2) {
        cin >> arr[1] >> arr[2];
        d[0] = 0;
        d[1] = arr[1];
        d[2] = arr[1] + arr[2];
    }
    else {
        cin >> arr[1];
        d[1] = arr[1];
    }

    for (int i = 3; i <= n; i++) {
        cin >> arr[i];
        d[i] = max(d[i - 3] + arr[i - 1] + arr[i], max(d[i - 2] + arr[i], d[i - 1]));
    }

    cout << d[n] << endl;
 
    return 0;
}