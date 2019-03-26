#include<queue>
#include<cstdio>
#include<string.h>
#include<map>
using namespace std;
struct POS {
	int x, y, d;
};
int board[1010][1010];
bool chk[1010][1010];
int dx[] = { 0, 0, 1 , -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int r, c;
		memset(board, 0, sizeof(board));
		memset(chk, 0, sizeof(chk));
		scanf("%d %d", &r, &c);
		int sx, sy;
		for (int i = 0; i < r; ++i) {
			char msg[1010];
			scanf("%s", msg);
			for (int j = 0; j < c; ++j) {
				if (msg[j] == 'O' || msg[j] == '0')
					board[i][j] = 1;
				else if (msg[j] == 'S') {
					sx = i; sy = j;
					board[i][j] = 1;
				}
				else if (msg[j] == 'G') 
					board[i][j] = 2;
			}
		}
		chk[sx][sy] = 1;
		queue<POS> q;
		q.push({ sx, sy, 0 });
		bool ans = 0;
		while (q.size()) {
			int x = q.front().x, y = q.front().y, d = q.front().d;
			q.pop();
			if (board[x][y] == 2) {
				printf("Shortest Path: %d\n", d);
				ans = 1; break;
			}
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (0 <= nx && nx < r && 0 <= ny && ny < c && board[nx][ny] && !chk[nx][ny]) {
					chk[nx][ny] = 1;
					q.push({ nx, ny, d + 1 });
				}
			}
		}
		if (!ans)puts("No Exit");
		while (q.size()) q.pop();
	}
}