#include<iostream>
using namespace std;

bool primeList[246913];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int i, j, cnt;
    cin >> N;
    primeList[0] = primeList[1] = true;
    for (i = 2; i*i < 246913; i++) {
        if (primeList[i]) continue;
        for (j = 2 * i; j < 246913; j += i) {
            primeList[j] = true;
        }
    }
    while (N != 0){
        M = 2 * N;
        cnt = 0;
        for (i = N + 1; i <= M; i++) {
            if (primeList[i]) continue;
            cnt++;
        }            
        cout << cnt << "\n";
        cin >> N;
    } 
    
    return 0;
}