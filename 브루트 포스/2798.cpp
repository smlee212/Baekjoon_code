#include<iostream>
using namespace std;

void blackjak(int n, int* card, int m);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int* card = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    blackjak(n, card, m);

    delete[] card;
    return 0;
}

void blackjak(int n, int* card, int m) {
    int max = 0, sum;
    for (int i = 0; i < n - 2; i++) {
        if (card[i] > m) continue;
        for (int j = i + 1; j < n - 1; j++) {
            if (card[i] + card[j] > m) continue;
            for (int k = j + 1; k < n; k++) {
                sum = card[i] + card[j] + card[k];
                if (sum <= m && sum >= max) max = sum;
            }
        }
    }
    cout << max << "\n";
}

