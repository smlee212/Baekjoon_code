#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define MAX 100001
int n, m;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int data;
    bool res;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> data;
        A.push_back(data);
    }
    sort(A.begin(), A.end());        

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> data;
        res = binary_search(A.begin(), A.end(), data);
        if (res) {
            cout << '1' << endl;
        }
        else {
            cout << '0' << endl;
        }
    }

    return 0;
}