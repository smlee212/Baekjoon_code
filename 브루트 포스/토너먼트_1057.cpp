#include <iostream>
#define endl '\n'
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, a, b; cin >> n >> a >> b;
    int vsize = n, r = 1;  
    while (1)
    {
        if (abs(a - b) <= 1 && min(a, b) % 2 == 1) {            
            break;
        }
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        vsize = (vsize % 2 == 1) ? vsize / 2 + 1 : vsize / 2;
        r++;
        if (vsize < 2) {
            r = -1;
            break;
        }
    }
    cout << r << endl;
    return 0;
}