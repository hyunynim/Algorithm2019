#include<bits/stdc++.h>
using namespace std;
int n;
int board[101][101];
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
bool chk(int x, int y, int s) {
	vector<int> cnt(8);
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if (0 > nx || 0 > ny || n <= nx || n <= ny) continue;
			cnt[i] += (board[nx][ny] == s);
		}
	}
	for (int i = 0; i < 8; ++i)
		if (cnt[i] >= 5) return 1;
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%1d", &board[i][j]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j]) {
				if (chk(i, j, board[i][j])) {
					printf("%d", board[i][j]); return 0;
				}
			}
		}
	}
}