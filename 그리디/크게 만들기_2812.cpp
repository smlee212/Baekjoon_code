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
int n, k;
string s;
deque<char> dq;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
	cin >> n >> k >> s;

	for (unsigned int i = 0; i < n; i++) { // 모든 숫자에 대해서
		while (k && !dq.empty() && dq.back() < s[i]) { // 이 전에 선택한 값보다 크면
			dq.pop_back(); // 이 전의 값을 제거한다.
			k--; 
		} 
		dq.push_back(s[i]); 
	} 

	for (unsigned int i = 0; i < dq.size() - k; i++) { 
		cout << dq[i]; 
	} 
	cout << "\n";


    return 0;
}