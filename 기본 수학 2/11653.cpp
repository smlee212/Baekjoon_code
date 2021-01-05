#include<iostream>
using namespace std;

void Factorization(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    Factorization(N);
    return 0;
}

void Factorization(int n) {
    int i;
    for (i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cout << i << "\n";
        }
    }
    if(n > 1) cout << n << "\n";
}