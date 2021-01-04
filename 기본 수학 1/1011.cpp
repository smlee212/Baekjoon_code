#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, x, y, i;
    int n, a, b, res;
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> x >> y;
        n = y - x;
        a = sqrt(n);
        b = n - a * a;
        if (b == 0) {
            res = 2 * a - 1;
        }
        else if (b <= a) {
            res = 2 * a;
        }
        else {
            res = 2 * a + 1;
        }        
        cout << res << "\n";
    }
    return 0;
}