#include<bits/stdc++.h>
using namespace std;
struct pos {
	int d, x, y, day, r;
};
int board[1010][1010];
int chk[2][11][1010][1010];
int main() {
	memset(chk, 0x3f, sizeof(chk));
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			scanf("%1d", &board[i][j]);
	queue<pos> q;
	q.push({ 1, 0, 0, 0, k });
	chk[0][k][0][0] = 1;
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	while (q.size()) {
		int d = q.front().d, x = q.front().x, y = q.front().y, day = q.front().day, r = q.front().r;
		q.pop();
		int nd = day ^ 1;
		if (x == n - 1 && y == m - 1) {
			printf("%d", d); return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board[nx][ny]) {
					if (chk[nd][r][x][y] > d + 1 && day) {
						chk[nd][r][x][y] = d + 1;
						q.push({ d + 1, x, y, nd, r });
					}

					else if(day == 0){
						if (r && chk[nd][r - 1][nx][ny] > d + 1) {
							q.push({ d + 1, nx, ny, nd, r - 1 });
							chk[nd][r - 1][nx][ny] = d + 1;
						}
					}
				}
				else {
					if (chk[nd][r][nx][ny] > d + 1) {
						q.push({ d + 1, nx, ny, nd, r });
						chk[nd][r][nx][ny] = d + 1;
					}
				}
			}
		}
	}
	printf("-1");
}