#include<iostream>
using namespace std;

int divsum(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int buf = n, cnt = 0;
    while (buf) {
        cnt++;
        buf /= 10;
    }
    int i = n - cnt * 9;
    for (i; i <= n; i++) {
        if (divsum(i) == n) {
            cout << i << "\n";
            return 0;
        }
    } 
    cout << "0\n";
    return 0;
}

int divsum(int n) {
    int res = n, buf = n;
    while (buf) {
        res += buf % 10;
        buf /= 10;
    }
    return res;
}