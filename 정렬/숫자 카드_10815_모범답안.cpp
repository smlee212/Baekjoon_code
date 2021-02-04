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

#define MAX 500000
int n, m;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    int input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, &arr[n]);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        cout << binary_search(arr, &arr[n], input) << " ";
    }
    return 0;
}

