#include<iostream>
using namespace std;

bool isPrime(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, i;
    cin >> M >> N;
    int sum = 0, min = 0;

    for (i = M; i <= N; i++) {
        if (i == 1) continue;
        if (isPrime(i)) {
            if (sum == 0) {
                min = i;
            }
            sum += i;
        }
    }
    if (sum == 0 && min == 0) {
        cout << "-1\n";
    }
    else {
        cout << sum << "\n" << min << "\n";
    }
    
    return 0;
}

bool isPrime(int n) {
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}