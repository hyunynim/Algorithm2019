#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#include<tuple>
#include<string.h>
using namespace std;

struct POS {
	int d, x, y;
};
bool chk[1010][1010];
bool fchk[1010][1010];
int board[1010][1010];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
		int n, m;
		scanf("%d %d", &n, &m);
		char msg[1010];
		int sx, sy;
		memset(chk, 0, sizeof(chk));
		memset(fchk, 0, sizeof(fchk));
		memset(board, 0, sizeof(board));
		queue<POS> fire;
		for (int i = 0; i < n; ++i) {
			scanf("%s", msg);
			for (int j = 0; j < m; ++j) {
				if (msg[j] == '#')
					board[i][j] = -1;
				else if (msg[j] == 'J') {
					sx = i;
					sy = j;
				}
				else if (msg[j] == 'F') {
					board[i][j] = 1;
					fire.push({ 1, i, j });
					fchk[i][j] = 1;
				}
			}
		}
		while (fire.size()) {
			int x = fire.front().x, y = fire.front().y, d = fire.front().d;
			fire.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 0) {
					board[nx][ny] = d + 1;
					fire.push({ d + 1, nx, ny });
				}
			}
		}
		queue<POS> q;
		bool noAns = 1;
		q.push({ 1, sx, sy });
		chk[sx][sy] = 1;
		while (q.size()) {
			int d = q.front().d, x = q.front().x, y = q.front().y;
			q.pop();
			if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && (board[x][y] >= d || board[x][y] == 0)) {
				printf("%d\n", d);
				noAns = 0;
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && !chk[nx][ny] && (board[nx][ny] > d + 1 || board[nx][ny] == 0)) {
					chk[nx][ny] = 1;
					q.push({ d + 1, nx, ny });
				}
			}
		}
		if (noAns)
			puts("IMPOSSIBLE");
		while (q.size()) q.pop();
}