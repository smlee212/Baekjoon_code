#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 100001
int n;
int Maxres = -1000;
int d[MAX] = { 0, };

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    int data;
    for (int i = 1; i <= n; i++)
    {
        cin >> data;
        d[i] = max(data, d[i-1] + data);
        Maxres = max(d[i], Maxres);
    }

    cout << Maxres << endl;

    return 0;
}