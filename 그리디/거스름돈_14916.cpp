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
using ll = long long;
#define endl '\n'
int n;
//int m;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;

    int cnt;
    int res = n;
    int min = 100000;
    
    if (n == 1 || n == 3) {
        cout << "-1" << endl;
        return 0;
    }

    if ((res % 5) % 2 == 0) { // 5로 나눈 나머지가 짝수일 경우    
        cnt = res / 5;
        res -= cnt * 5;
        cnt += res / 2;
    }
    else { // 5로 나눈 나머지가 홀수일 경우
        cnt = (res / 5) - 1;       
        res -= 5 * cnt;
        cnt += res / 2;
    }
    cout << cnt << endl;

    return 0;
}