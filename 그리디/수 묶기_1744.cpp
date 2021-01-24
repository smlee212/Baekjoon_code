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
int N, oneCnt, zeroCnt;
vector<int> positive;
vector<int> negative;

//int m;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
	cin >> N;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > 1) positive.push_back(tmp);
		else if (tmp < 0) negative.push_back(tmp);
		else if (tmp == 0) zeroCnt++;
		else oneCnt++;
	}

	if (positive.size() % 2 == 1) // 1 보다 큰 양수의 개수가 홀수이면 1을 추가해준다.
		positive.push_back(1);
	if (negative.size() % 2 == 1) { // 음수의 개수가 홀수이고
		if (zeroCnt == 0) negative.push_back(1); // 0이 없다면 1을 추가해준다.
		else negative.push_back(0); // 0이 있다면 0을 추가해준다.
	}

	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());


	int sum = oneCnt; // 1은 그냥 더해준다.
	for (int i = 0; i < positive.size(); i += 2) // 홀수개이면 남은 수에 1이 곱해져 그대로이다.
		sum += positive[i] * positive[i + 1];
	for (int i = 0; i < negative.size(); i += 2)
		sum += negative[i] * negative[i + 1];
	cout << sum << endl;

    return 0;
}