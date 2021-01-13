#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 8+1

int n, m;
int arr[MAX] = { 0, }; // 출력할 원소를 담아두는 곳
bool visited[MAX] = { 0, }; // 출력할 원소들을 표시

void P(int cnt, int num) {        
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i; 
            P(cnt + 1, i+1);
            visited[i] = false;

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    P(0, 1);
    
    return 0;
}