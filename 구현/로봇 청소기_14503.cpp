#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[51][51];
int n, m;
int x, y, d;
int cnt;
int x_dir[4] = {0,1,0,-1};
int y_dir[4] = {-1,0,1,0};
int x_back[4] = {0,-1,0,1};
int y_back[4] = {1,0,-1,0};
int flag = 0;
int dfs(int x,int y,int d) {
	if (flag) return 0;
	if (arr[y][x] == 0) {
		arr[y][x] = 2;
		cnt++;
	}
	for (int i = 1; i <= 4; i++) {
		int d_new = d - i;
		if (d_new < 0) d_new = d - i + 4;
		int x_new = x + x_dir[d_new];
		int y_new = y + y_dir[d_new];
		if (x_new < m && x_new >= 0 && y_new < n && y_new >= 0) {
			if (arr[y_new][x_new] == 0) { 
				dfs(x_new, y_new, d_new);
			}
		}
	}
	int x_new = x + x_back[d];
	int y_new = y + y_back[d];
	if (x_new < m && x_new >= 0 && y_new < n && y_new >= 0) {
		if (arr[y_new][x_new] != 1) {
			dfs(x_new, y_new, d);
		}
	}
	flag = 1;
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &y, &x, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(x, y, d);
	printf("%d\n", cnt);
}