#include<iostream>
using namespace std;

bool primeList[1000001];
void isPrime(int m, int n);
void isPrime_0(int m, int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;
    isPrime_0(M, N);
    return 0;
}

void isPrime(int m, int n) {
    int i, j, b;
    for (i = m; i <= n; i++) {
        b = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                b = 0;
                break;
            }
        }
        if (b == 1 && i != 1) {
            cout << i << "\n";
        }
    }
}

void isPrime_0(int m, int n) {
    int i, j;
    for (i = 2; i < n; i++) {
        if (primeList[i]) continue;
        for (j = 2 * i; j < n; j += i) { // i를 제외한 배수들을 true로 만든다.
            primeList[j] = true;
        }
    }
    for (i = m; i <= n; i++) {
        if (primeList[i] || i == 1) continue;
        cout << i << "\n";
    }
}

