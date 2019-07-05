#include<bits/stdc++.h>
using namespace std;
int board[1010][1010];
int chk[2][11][1010][1010];
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &board[i][j]);
			for(int q = 0; q<=k; ++q)
				chk[0][q][i][j] = chk[1][q][i][j] = -123456789;
		}
	}
	queue<tuple<int, int, int, int, int>> q;
	q.push({ -1, 0, 0, 0, k });
	chk[0][k][0][0] = -1;
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	while (q.size()) {
		int d, x, y, day, r;
		tie(d, x, y, day, r) = q.front(); q.pop();
		int nd = day ^ 1;
		if (x == n - 1 && y == m - 1) {
			printf("%d", -d); return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board[nx][ny]) {
					if (chk[nd][r][x][y] < d - 1 && day) {
						chk[nd][r][x][y] = d - 1;
						q.push({ d - 1, x, y, nd, r });
					}

					else if(day == 0){
						if (r && chk[nd][r - 1][nx][ny] < d - 1) {
							q.push({ d - 1, nx, ny, nd, r - 1 });
							chk[nd][r - 1][nx][ny] = d - 1;
						}
					}
				}
				else {
					if (chk[nd][r][nx][ny] < d - 1) {
						q.push({ d - 1, nx, ny, nd, r });
						chk[nd][r][nx][ny] = d - 1;
					}
				}
			}
		}
	}
	printf("-1");
}