#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 1001
int n;
int s[MAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    s[1] = 1;
    s[2] = 2;
    for (int i = 3; i <= n; i++) {
        s[i] = (s[i - 1] + s[i - 2]) % 10007;
    }

    cout << s[n] << endl;

    return 0;
}