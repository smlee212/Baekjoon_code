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
//int n;
int arr[2] = { 0, };

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    char c, buf;
    c = getchar();
    arr[c - '0']++;

    buf = getchar();
    while (buf != '\n') {
        if (buf != c) {
            c = buf;
            arr[c - '0']++;
        }
        buf = getchar();        
    }

    if (arr[0] <= arr[1]) {
        cout << arr[0] << endl;
    }
    else {
        cout << arr[1] << endl;
    }

    return 0;
}

