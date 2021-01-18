#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<int> coin(10,0);
int n, k;

void greedy() {
    int res = 0, index;
    while (k) {
        index = n - 1;
        while (k < coin[index]) {
            index--;
        }
        res += k / coin[index];
        k = k % coin[index];
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    greedy();


    return 0;
}