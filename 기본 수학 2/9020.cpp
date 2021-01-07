#include<iostream>
using namespace std;

bool notprime[10001]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, i, j, n, a, b;
    cin >> T;

    for (i = 2; i * i < 10001; i++) {
        for (j = i + i; j < 10001; j += i) {
            notprime[j] = true;
        }
    }
    notprime[0] = true;
    notprime[1] = true;

    for (i = 0; i < T; i++) {
        cin >> n;
        a = n / 2;
        b = n / 2;
        while (notprime[a] || notprime[b]) {
            a--;
            b++;
        }
        cout << a << " " << b << "\n";
    }

    return 0;
}