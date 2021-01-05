#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, x1, x2, y1, y2, r1, r2;
    cin >> T;
    int i;
    for (i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double R = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
        if (R == 0 && r1 == r2) {
            cout << "-1\n";
        }
        else if (R > r1 + r2) {
            cout << "0\n";
        }
        else if (R == r1 + r2) {
            cout << "1\n";
        }
        else if (r1 > R + r2 || r2 > R + r1) {
            cout << "0\n";
        }
        else if (r1 == R + r2 || r2 == R + r1) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    }
    return 0;
}