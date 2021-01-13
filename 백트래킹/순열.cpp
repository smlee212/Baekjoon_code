#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Permutation(vector<int>& a, int start, int end);
void HeapPermutation(vector<int>& a, int size, int n);

// next_permutation을 이용하여 n개의 숫자에 대한 모든 순열 구하기
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  
  int psize;
  vector<int> P(psize);

  // next_permutation의 핵심 로직 공간
  do {
      for (int i = 0; i < psize; i++) {
          cout << P[i] << " ";
      }
      cout << "\n";
  } while (next_permutation(P.begin(), P.end()));
    	
    return 0;
}

// 기본적인 순열 알고리즘 (순열 출력)
// 2번의 스왑이 추가적으로 실행된다.
void Permutation(vector<int>& a, int start, int end) { 
	if (start = end) {
		for (const auto it : a) {
			cout << it << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = start; i <= end; i++) { // i번째 값을 선택한다.
			swap(a[start], a[i]); // i번째 값을 제외한 나머지에 대해 순열을 구해야 한다.
			Permutation(a, start + 1, end); // 그러므로, i번째 값을 start로 보낸 후, 나머지에 대해 순열 재귀
			swap(a[start], a[i]); // 원상복귀 해줌
		}
	}
}

// 힙 알고리즘
void HeapPermutation(vector<int>& a, int size, int n)
{
    // 사이즈가 1이면 Array를 출력합니다.
    if (size == 1) {
        for (const auto it : a) {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        // 재귀 함수 호출
        HeapPermutation(a, size - 1, n);
        
        if (i < size - 1) {
            // 사이즈가 홀수면 첫번째와 마지막을 스왑합니다.
            if (size % 2 == 1)
                swap(a[0], a[size - 1]);

            // 사이즈가 짝수면 i번째와 마지막을 스왑합니다.
            else
                swap(a[i], a[size - 1]);
        }
    }
}
