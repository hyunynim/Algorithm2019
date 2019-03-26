#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int board[1010][1010];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool chk[1010101];
bool check[1010][1010];
struct POS {
	int x, y;
};
POS area[1010][1010];
void bfs(int x, int y, queue<POS> & ans) {
	queue<POS> q;
	q.push({ x, y });
	check[x][y] = 1;
	if (board[x][y] == 0) return;
	while (q.size()) {
		int curX = q.front().x;
		int curY = q.front().y;
		ans.push(q.front()); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] && !check[nx][ny]) {
				check[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	int idx = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!check[i][j]) {
				queue<POS> ans;
				bfs(i, j, ans);
				int sz = ans.size();
				while (ans.size()) {
					int x = ans.front().x;
					int y = ans.front().y; ans.pop();
					area[x][y].y = sz;
					area[x][y].x = idx;
				}
				++idx;
			}
		}
	}
	puts("");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", area[i][j].y);
		puts("");
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 0) {
				int sum = 1;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < m && !chk[area[nx][ny].x]) {
						sum += area[nx][ny].y;
						chk[area[nx][ny].x] = 1;
					}
				}
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < m)
						chk[area[nx][ny].x] = 0;
				}
				ans = max(ans, sum);
			}
		}
	}
	printf("%d", ans);
}