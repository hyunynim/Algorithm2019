#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
struct POS {
	int x, y;
};
bool chk[101][101];
int board[101][101];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);

	queue<POS> q;
	q.push({ 0, 0 });
	chk[0][0] = 1;
	int dx[] = { 0, 1 };
	int dy[] = { 1, 0 };
	while (q.size()) {
		int x, y;
		x = q.front().x; y = q.front().y; q.pop();
		if (x == n - 1 && y == n - 1) {
			printf("HaruHaru");
			return 0;
		}
		for (int i = 0; i < 2; ++i) {
			int nx = x + dx[i] * board[x][y];
			int ny = y + dy[i] * board[x][y];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !chk[nx][ny]) {
				chk[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	printf("Hing");
}