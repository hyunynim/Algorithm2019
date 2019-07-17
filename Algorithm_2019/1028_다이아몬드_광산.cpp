#include<bits/stdc++.h>
using namespace std;
int board[757][757];
int sum[4][757][757];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int ans;
int main() {
	int r, c; scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			scanf("%1d", &board[i][j]);
			if (board[i][j]) {
				sum[0][i][j] = sum[0][i - 1][j + 1] + 1;
				sum[1][i][j] = sum[1][i - 1][j - 1] + 1;
				ans = 1;
			}
		}
	}
	for (int i = r; i >= 1; --i) {
		for (int j = c; j >= 1; --j) {
			if (board[i][j]) {
				sum[2][i][j] = sum[2][i + 1][j - 1] + 1;
				sum[3][i][j] = sum[3][i + 1][j + 1] + 1;
			}
		}
	}
	int sz = min((r + 1) / 2, (c + 1) / 2);
	while (sz > 1) {
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				bool chk = 1;
				int szMin = 1e9;
				for (int k = 0; k < 4; ++k) {
					int nx = i + (sz - 1) * dx[k];
					int ny = j + (sz - 1) * dy[k];
					if (szMin < sz || nx < 1 || nx > r || ny < 1 || ny > c) {
						chk = 0; break;
					}
					szMin = min(szMin, sum[k][nx][ny]);
				}
				if (chk && szMin >= sz) {
					printf("%d", sz); return 0;
				}
			}
		}
		--sz;
	}
	printf("%d", ans);
}