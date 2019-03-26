#include<cstdio>
bool board[1010][1010];
int area[1010][1010];
int n;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dfs(int x, int y, int idx) {
	if (area[x][y]) return 0;
	area[x][y] = idx;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && area[nx][ny] == 0)
			dfs(nx, ny, idx);
	}
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char msg[1010];
		scanf("%s", msg);
		for (int j = 0; j < n; ++j) {
			if (msg[j] == '*')
				board[i][j] = 1;
			else
				area[i][j] = -1;
		}
	}
	int idx = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (dfs(i, j, idx)) ++idx;

	printf("%d", idx - 1);
}