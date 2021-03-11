#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MAX 10
int K;
char MAP[MAX];
bool num[MAX];
vector<string> Answer;
vector<char> V;

void Input() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> MAP[i];
    }
}

bool Check(int Idx, char c) {
    if (c == '<') {
        if (V[Idx] - '0' < V[Idx + 1] - '0') return true;
        else return false;
    }
    else if (c == '>') {
        if (V[Idx] - '0' > V[Idx + 1] - '0') return true;
        else return false;
    }
}

bool Calculate() {
    for (int i = 0; i < K; i++) {
        if (Check(i, MAP[i]) == false) return false;
    }
    return true;
}

void DFS(int Cnt)
{
    if (Cnt == K + 1) {
        if (Calculate() == true) {
            string S_Tmp = "";
            for (int i = 0; i < V.size(); i++) {
                S_Tmp = S_Tmp + V[i];
            }
            Answer.push_back(S_Tmp);
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (num[i] == true) continue;
        num[i] = true;
        V.push_back(i + '0');
        DFS(Cnt + 1);
        V.pop_back();
        num[i] = false;
    }
}

void Solution() {
    DFS(0);
    sort(Answer.begin(), Answer.end());
    cout << Answer.at(Answer.size() - 1) << endl;
    cout << Answer.at(0) << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}