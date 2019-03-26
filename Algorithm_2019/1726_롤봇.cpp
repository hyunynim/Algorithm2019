#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;

int chk[4][101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int board[101][101];
int n, m;
typedef tuple<int, int, int, int, int> T;

void go(int & x, int & y, int f) {
	while (0 <= x && x < n && 0 <= y && y < m && board[x + dx[f]][y + dy[f]] == 0) {
		x += dx[f];
		y += dy[f];
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &board[i][j]);
			for (int k = 0; k < 4; ++k)
				chk[k][i][j] = -1e9;
		}
	}
			int sx, sy, sf, fx, fy, ff;
	scanf("%d %d %d %d %d %d", &sx, &sy, &sf, &fx, &fy, &ff);
	--ff; --sf;
	--sx; --sy;
	--fx; --fy;
	priority_queue<T> q;
	q.push({ 0, sf, sx, sy, 1 });
	chk[sf][sx][sy] = 0;
	while (q.size()) {
		int d, f, x, y, stop;
		tie(d, f, x, y, stop) = q.top();
		q.pop();
		if (x == fx && y == fy && f == ff) {
			printf("%d", -d); return 0;
		}
		for (int i = 0; i < 4; ++i) {
			if (((f == 0 || f == 1) && (i == 2 || i == 3))
				|| ((f == 2 || f == 3) && ( i == 0 || i == 1))) {
				if (chk[i][x][y] < d) {
					chk[i][x][y] = d - 1;
					q.push({ d - 1, i, x, y, 1 });
				}
			}
			else if (f == i) {
				int nx = x, ny = y;
				go(nx, ny, f);
				q.push({ d - 1, f, nx, ny, 1 });
			}
		}
	}
}