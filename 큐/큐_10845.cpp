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
using namespace std;
using ll = long long;
#define endl '\n'

#define MAX 10000

class que {
public:
    que() {
        r = 0;
        f = 0;
        size_q = MAX;
        data = new int[size_q];
    }
    ~que() {
        delete[] data;
    }

    void push(int x) {
        if (!isfull()) {
            data[r] = x;
            r = (r + 1) % size_q;
        }
        else
            cout << "-1" << endl;
    }
    void pop() {
        if (!isempty()) {
            cout << data[f] << endl;
            f = (f + 1) % size_q;
        }
        else
            cout << "-1" << endl;
    }
    int size() {
        return r - f;
    }
    void front() {
        if(isempty() == 0)
            cout << data[f] << endl;
        else
            cout << "-1" << endl;
    }
    void back() {
        if (isempty() == 0)
            cout << data[r - 1] << endl;
        else
            cout << "-1" << endl;
    }
    int isempty() {      
        if (r == f) return 1;
        else return 0;
    }
    bool isfull() {
        return ((r + 1) % size_q == f);
    }

private:
    int r;
    int f;
    int size_q;
    int *data;
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, x; cin >> n;
    string s;
    que q;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q.push(x);
        }
        else if (s == "pop") {
            q.pop();
        }
        else if (s == "size") {
            cout << q.size() << endl;
        }
        else if (s == "empty") {
            cout << q.isempty() << endl;
        }
        else if (s == "front") {
            q.front();
        }
        else if (s == "back") {
            q.back();
        }
    }
    
    return 0;
}