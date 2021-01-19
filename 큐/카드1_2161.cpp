#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, buf; cin >> n;
    queue<int> a, b;
    for (int i = 1; i <= n; i++) {
        a.push(i);
    }

    cout << a.front() << ' '; // 제일 위에 있는 카드 저장하고
    a.pop(); // 버림

    while (!a.empty()) {
        buf = a.front(); // 제일 위에 있는 카드 저장하고
        a.pop(); // 뽑아내서
        a.push(buf); // 제일 아래에 넣음

        cout << a.front() << ' '; // 제일 위에 있는 카드 저장하고
        a.pop(); // 버림
    }

    return 0;
}
