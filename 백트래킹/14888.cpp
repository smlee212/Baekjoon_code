#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void calculate(vector<int> a, int i, int c, long res);

vector<int> calc(4);
long MAX = -1000000000;
long MIN = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }    
    for (int i = 0; i < 4; i++) {
        cin >> calc[i];
    }
    calculate(A, 0, 4, 0);
    cout << MAX << "\n" << MIN << "\n";
    return 0;
}

void calculate(vector<int> a, int i, int c, long res) {       
    switch (c)
    {
    case 0:
        res += a[i];
        break;
    case 1:
        res -= a[i];
        break;
    case 2:
        res *= a[i];
        break;
    case 3:
        if (res < 0) {
            res = -((-res) / a[i]);
        }
        else {
            res /= a[i];
        }
        break;
    case 4 :
        res = a[0];
        break;
    }  
    if (i == a.size() - 1) {
        if (res > MAX) {
            MAX = res;
        }
        if (res < MIN) {
            MIN = res;
        }
        //cout << "max = " << MAX << " min = " << MIN << "\n";
        return;
    }
    for (int j = 0; j < 4; j++) {            
        if (calc[j]) {
            calc[j]--;
            //cout << "[" << i << "] ";
            calculate(a, i+1, j, res);
            calc[j]++;
        }
    }            
}


