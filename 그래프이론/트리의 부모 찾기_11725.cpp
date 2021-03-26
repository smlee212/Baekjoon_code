#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n;
bool visited[100001];
int parent[100001];
vector<int> tree[100001];

void findP(int node) {
    visited[node] = true;
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if (!visited[next]) {
            parent[next] = node;
            findP(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    findP(1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << endl;
    }

    return 0;
}