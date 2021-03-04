#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

#define MAX 2001
int N; 
int leftCards[MAX], rightCards[MAX];
int memo[MAX][MAX]; // 왼쪽이 i번째 카드이고, 오른쪽이 j번째 카드일 때의 최대값

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N; 
	for (int i = 0; i < N; i++) 
		cin >> leftCards[i]; 
	for (int i = 0; i < N; i++) 
		cin >> rightCards[i]; 
	// 재귀가 돌듯이 마지막 카드에서부터 더해져야 한다. 
	for (int i = N - 1; i >= 0; i--) 
	{ 
		for (int j = N - 1; j >= 0; j--) 
		{ // 각각의 규칙을 적용할 때, 그 중 최대값을 저장한다. 
			memo[i & 1][j] = max({ memo[(i + 1) & 1][j], memo[(i + 1) & 1][j + 1], 
				(leftCards[i] > rightCards[j] ? memo[i & 1][j + 1] + rightCards[j] : 0) }); 
		} 
	} 
	cout << memo[0][0];
	return 0;
}