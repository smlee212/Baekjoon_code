#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int tc = 1, cnt = 0;
string str;

void sol() {
    deque<char> dq;
    unsigned slen = str.length();
    for (int i = 0; i < slen; i++) {
        if (str[i] == '{') {
            dq.push_back('{');
        }
        else if (str[i] == '}') { 
            if (dq.empty()) { // dq가 비어있다면
                dq.push_back('{'); // 바꿔서 넣어준다.
                cnt++;
            }
            else if (dq.back() == '{') { // 안정적이므로 지워준다.
                dq.pop_back();
            }
        }
    }
    
    if (!dq.empty()) {
        cnt += dq.size() / 2;
    }

    cout << tc << ". " << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> str;
    while (str.find('-') == string::npos) {
        sol();
        tc++; cnt = 0;
        cin >> str;
    } 

    return 0;
}