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
#include <cstdio>
using namespace std;
#define endl '\n'
using ll = long long;
//////////////////////////////

//#define MAX 1000000
int n;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        dq.push_back(data);
    }

    sort(dq.begin(), dq.end());

    int sum = 0, res = 0;
    for (int i = 0; i < n; i++) {
        sum += dq.front();
        res += sum;
        dq.pop_front();
    }

    cout << res << endl;    

    return 0;
}

