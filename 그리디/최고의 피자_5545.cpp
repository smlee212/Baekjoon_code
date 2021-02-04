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
int n, a, b, c;
int w, cal; // 가격, 열량
int maxres = 0;
deque<int> d;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n        // 토핑 개수
        >> a >> b   // 도우 가격, 토핑 가격
        >> c;       // 도우 열량
    int data;
    for (int i = 0; i < n; i++) {   // n개의 토핑 열량
        cin >> data;
        d.push_back(data);
    }
    // 가격 : 도우 + k * 토핑 = a + k * b
    // 열량 : 도우 + k * 토핑 = c + k개의 토핑의 열량 합
    //
    // 1원 당 열량 : 열량 / 가격 
   
    sort(d.begin(), d.end()); // 열량 크기 순 정렬

    // 초기 상태
    w = a;
    cal = c;
    maxres = cal / w;

    // 열량이 큰 순서대로 토핑 추가
    for (int i = n -1; i >= 0; i--) {
        w += b;
        cal += d[i];
        if (cal / w > maxres) {
            maxres = cal / w;
        }
    }
    
    cout << maxres << endl;

    return 0;
}

