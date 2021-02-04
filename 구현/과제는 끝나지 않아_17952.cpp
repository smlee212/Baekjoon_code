#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int n, m, a, t;
int res = 0;
deque<int> score, Time;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m == 0) {
            if (Time.empty()) continue;
            if (Time[0] == 1) {
                res += score[0];
                score.pop_front();
                Time.pop_front();
            }
            else {
                Time[0]--;
            }
        }
        else {
            cin >> a >> t;
            if (t == 1) {
                res += a;
            }
            else {
                t--;
                score.push_front(a);
                Time.push_front(t);
            }
        }
    }
    cout << res << endl;

    return 0;
}