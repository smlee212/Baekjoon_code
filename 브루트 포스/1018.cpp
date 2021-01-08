#include<iostream>
#include<vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector< vector<char> > board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];

    int F, T, buf, Min = 64;
    int a = 0, b = 0, x, y, cnt = 0;;
    while (b + 8 <= m) {
        T = 0;
        F = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                x = a + i;
                y = b + j;
                if ((x + y) % 2 == 1) {
                    if (board[x][y] == 'B') T++;
                    else F++;
                }
                else {
                    if (board[x][y] == 'W') T++;
                    else F++;
                }
            }
        }
        buf = (T < F) ? T : F;
        if (buf < Min) {
            Min = buf;
        }
        a++;
        if (a + 8 > n) {
            a = 0;
            b++;
        }
    }

    cout << Min << "\n";

    return 0;
}
