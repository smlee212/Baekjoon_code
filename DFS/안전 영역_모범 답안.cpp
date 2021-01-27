#include <stdio.h>

int N;		// 2 ~ 100

int Map[100][100];
int Board[100][100];
int MHeight;
int MSafe;

void dfs(int y, int x, int count) {
	Board[y][x] = count;

	if (x + 1 < N) {
		if (Board[y][x + 1] == 0) {
			dfs(y, x + 1, count);
		}
	}

	if (y + 1 < N) {
		if (Board[y + 1][x] == 0) {
			dfs(y + 1, x, count);
		}
	}

	if (x - 1 >= 0) {
		if (Board[y][x - 1] == 0) {
			dfs(y, x - 1, count);
		}
	}

	if (y - 1 >= 0) {
		if (Board[y - 1][x] == 0) {
			dfs(y - 1, x, count);
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] > MHeight)
				MHeight = Map[i][j];
		}
	}

	int count;
	for (int h = 0; h < MHeight; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Map[i][j] <= h)
					Board[i][j] = -1;				
				else
					Board[i][j] = 0;				
			}
		}
		
		count = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Board[i][j] == 0) {
					dfs(i, j, count++);
				}
			}
		}

		if (count - 1 > MSafe)
			MSafe = count - 1;
	}

	printf("%d\n", MSafe);

	return 0;
}