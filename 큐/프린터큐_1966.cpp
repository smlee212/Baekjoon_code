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
bool num[5001] = { 0, };

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    int n, m, index, MAX, cnt;    
    for (int i = 0; i < T; i++) {
        cin >> n >> m;
        vector<int> v(n);
        priority_queue<int> pq;
        for (int j = 0; j < n; j++) { 
            cin >> v[j]; // v[i]는 문서 i의 우선순위를 원소로 가지고 있다.
            pq.push(v[j]); // 우선순위를 저장
        }
        index = 0;
        cnt = 1;
        MAX = pq.top();
        while (cnt <= n) { // n번 모두에 대해 확인
            if (v[index] == MAX) { // 가장 높은 우선순위를 가지고
                if (index == m) { // 그 문서가 찾고자 하는 문서일 때
                    cout << cnt << endl;
                    break;
                }
                v[index] = 0; // 제외
                pq.pop();
                MAX = pq.top(); // 다음으로 큰 우선순위를 가져온다.
                cnt++;
            }
            index = (index + 1) % n; // 다음 index로 넘어감
        }
    }

    return 0;
}
