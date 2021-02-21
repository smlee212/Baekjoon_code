#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

enum ISPALINDROME {
	PALINDROME = 0,
	SEMI_PALINDROME,
	NOT_PALINDROME
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;

	for (int tc = 0; tc < n; tc++) {
		string str; cin >> str;

		int res = PALINDROME;

		for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
			if (str[i] == str[j]) {
				continue;
			}

			if (str[i + 1] != str[j] && str[i] != str[j - 1]) {
				res = NOT_PALINDROME;
				break;
			}

			bool isPalindrome = false;

			for (int k = 0; k < 2 && isPalindrome == false; k++) {
				int start = i;
				int end = j;

				k == 0 ? start++ : end--;

				isPalindrome = true;

				for (int a = start, b = end; a < b; a++, b--) {
					if (str[a] != str[b]) {
						isPalindrome = false;
						break;
					}
				}
			}

			res = isPalindrome ? SEMI_PALINDROME : NOT_PALINDROME;
			break;
		}

		cout << res << endl;
	}

	return 0;
}