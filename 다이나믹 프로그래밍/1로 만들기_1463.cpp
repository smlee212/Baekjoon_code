#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int n;
int num[1000001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   

    cin >> n;

    for (int i = 2; i <= n; i++) {
        num[i] = num[i - 1] + 1; // -1 을 한 경우
        
        if (i % 2 == 0) { // 2로 나누어 떨어질 경우
            num[i] = min(num[i], num[i / 2] + 1); 
        }

        if (i % 3 == 0) { // 3으로 나누어 떨어질 경우
            num[i] = min(num[i], num[i / 3] + 1);
        }
    }
    
    cout << num[n] << endl;

    return 0;
}