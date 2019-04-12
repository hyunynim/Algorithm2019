#include<bits/stdc++.h>

using namespace std;

int board[1010][1010];
int d[1010][1010];

int dy[] = { 1, 1, 1 };
int dx[] = { 0, 1, -1};
int n, m, sx, sy, cnt;
int go(int x, int y, int c) {
	if (0 > x || x >= n || 0 > y || y >= m || board[x][y] == -1) return -1e9;
	int & res = d[x][y];
	if (res != -2)
		return res;
	res = -1;
	if (board[x][y] == 2)
		res = max(res, c);
	for (int i = 0; i < 3; ++i) {
		int nx = dx[i] + x, ny = dy[i] + y, nc = board[nx][ny] == 1 ? c + 1 : c;
		res = max(res, go(nx, ny, nc));
	}
	return res;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		char msg[1010];
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) {
			d[i][j] = -2;
			if (msg[j] == 'R') {
				sx = i; sy = j;
			}
			else if (msg[j] == 'C')
				board[i][j] = 1;
			else if (msg[j] == 'O') {
				board[i][j] = 2;
				++cnt;
			}
			else if (msg[j] == '#')
				board[i][j] = -1;
		}
	}
	if (cnt == 0) {
		printf("-1"); return 0;
	}
	printf("%d", go(sx, sy, 0));
}