#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
using ll = long long;
#define endl '\n'
bool num[5001] = { 0, };

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    int index = 0, i;
    queue<int> q;
    for (int j = 0; j < n; j++) {
        i = 0;
        while (i < k) {
            if (index == n) {
                index = 1;
            }
            else {
                index++;
            }
            if (!num[index]) i++;
        }
        q.push(index);
        num[index] = true;
    }
    
    cout << '<';
    for (i = 0; i < n - 1; i++) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << '>';
    return 0;
}

//////////////////////////////
int main(){
  vector <int> arr;
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) {
      arr.push_back(i);
  }
  int indi = 0;
  cout << "<";
  int count = 1;
  for (int i = 1; count < a; i++) {
      indi = (indi + b - 1) % arr.size();
      cout << arr[indi] << ", ";
      arr.erase(arr.begin() + indi);
      count++;
  }
  cout << arr.front() << ">";
}