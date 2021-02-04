#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   

    int tc, n, m, x, y, dist;
    int index = 0;

    cin >> tc;
    while (tc--) {
        vector<int> dx, dy;
        deque<int> dq;
        bool visited[101] = { 0, };

        cin >> n;  
        for (int i = 0; i < n + 2; i++) {
            cin >> x >> y;
            dx.push_back(x);
            dy.push_back(y);
        }
        
        dq.push_back(0);
        visited[0] = true;

        while(!dq.empty()) {
            index = dq.front(); // 건너온 좌표를 현재 좌표로 지정한다.
            dq.pop_front();

            if (index == n + 1) { // 이 좌표가 도착 지점이라면 성공이다.
                break;
            }

            x = dx[index];
            y = dy[index];            

            for (int i = 1; i < n + 2; i++) { // 갈 수 있는 다음 좌표를 찾아본다.
                dist = abs(dx[i] - x) + abs(dy[i] - y);
                if (dist <= 1000 && !visited[i]) { // 방문하지 않았고, 갈 수 있다면
                    dq.push_back(i); // 다음 좌표로 넘어간다.
                    visited[i] = true;
                }
            }
        }
        
        if (index == n + 1) {
            cout << "happy" << endl;
        }
        else {
            cout << "sad" << endl;
        }
    }

    return 0;
}