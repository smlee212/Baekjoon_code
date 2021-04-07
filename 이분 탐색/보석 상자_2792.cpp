#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, M;
int color[300001];
bool check(int n) {
    int num = 0;
    for (int i = 0; i < M; i++) {
        num += color[i] / n;
        if (color[i] % n) num ++;
    }
    if (num <= N) return true;
    return false;
}
 
int main() {
    cin >> N>>M;
    int high=0, low = 1;
    for (int i = 0; i < M; i++) {
        cin >> color[i];
        high = max(high,color[i]); 
    }
    while (low <= high) {
        int mid = (low + high) / 2;
        bool pos = true;
        if (!check(mid)) low = mid + 1; 
        else high = mid - 1;  
    }
    cout << low;
}