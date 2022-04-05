#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, Max, Mid, Min;
    cin >> a >> b >> c;
    while (1) {
        if (a == b && a == c && a == 0) {
            break;
        }
        Max = max(max(a, b), c);
        Min = min(min(a, b), c);
        Mid = a + b + c - Max - Min;
        if (Max * Max == Min * Min + Mid * Mid) {
            cout << "right\n";
        }
        else {
            cout << "wrong\n";
        }
        cin >> a >> b >> c;
    }    
    return 0;
}