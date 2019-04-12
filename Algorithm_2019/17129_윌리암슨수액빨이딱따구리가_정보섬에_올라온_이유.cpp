#include<bits/stdc++.h>

using namespace std;
int board[3030][3030];
bool chk[3030][3030];
struct POS {
	int x, y, d;
};
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	int n, m, sx, sy; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		char msg[1010];
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) {
			board[i][j] = msg[j] - '0';
			if (board[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
	}
	chk[sx][sy] = 1;
	queue<POS> q;
	q.push({ sx, sy, 0 });
	while (q.size()) {
		int x, y, d;
		x = q.front().x; y = q.front().y; d = q.front().d;
		q.pop();
		if (board[x][y] != 1 && board[x][y] != 2 && board[x][y]) {
			puts("TAK");
			printf("%d", d);
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !chk[nx][ny] && board[nx][ny] != 1) {
				chk[nx][ny] = 1;
				q.push({ nx, ny, d + 1 });
			}
		}
	}
	printf("NIE");
}