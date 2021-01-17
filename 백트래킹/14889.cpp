#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int MIN = 20000;
int arr_1[10] = { 0, };
int arr_2[10] = { 0, };
bool visited[21] = { 0, };
void C(int cnt, int num, vector<vector<int>> S);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    m = n / 2;
    vector<vector<int>> S(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    C(0, 1, S);
    cout << MIN << "\n";

    return 0;
}

void C(int cnt, int num, vector<vector<int>> S) {
    if (MIN == 0) return;
    if (cnt == m) {
        int k = 0, res_1 = 0, res_2 = 0, buf;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                arr_2[k] = i;
                k++;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                res_1 += S[arr_1[i] - 1][arr_1[j] - 1];
                res_2 += S[arr_2[i] - 1][arr_2[j] - 1];
            }
        }
        buf = abs(res_1 - res_2);
        if (buf < MIN) {
            MIN = buf;
        }
        return;
    }
    for (int i = num; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr_1[cnt] = i;
            C(cnt + 1, i + 1, S);
            visited[i] = false;
        }
    }
}