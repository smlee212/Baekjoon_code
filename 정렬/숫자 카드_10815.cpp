#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
#define endl '\n'
using ll = long long;
//////////////////////////////

#define MAX 100
int n, m;
bool num[20000001] = { 0, };
int res;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> number;
        num[number + 10000000] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> number;
        if (num[number + 10000000]) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
    cout << endl;

    return 0;
}