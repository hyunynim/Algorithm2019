#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;
bool chk[101][101];
struct POS {
	int x, y;
};
int n, m, k;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool board[101][101];
void bfs(int x, int y) {
	queue<POS> q;
	q.push({ x, y });
	chk[x][y] = 1;
	while (q.size()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !chk[nx][ny] && board[nx][ny]) {
				q.push({ nx, ny });
				chk[nx][ny] = 1;
			}
		}
	}
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(chk, 0, sizeof(chk));
		memset(board, 0, sizeof(board));
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			board[a][b] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] && !chk[i][j]) {
					bfs(i, j);
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
}