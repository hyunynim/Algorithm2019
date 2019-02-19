#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

struct dk {
	int x, y, d;
};
bool chk[202][202];
int main() {
	int n; scanf("%d", &n);
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	queue<dk> q;
	q.push({ a, b, 0 });
	chk[a][b] = 1;
	int dx[] = { -2, -2, 0, 0, 2, 2 };
	int dy[] = { -1, 1, -2, 2, -1, 1 };
	while (q.size()) {
		int x = q.front().x, y = q.front().y, dist = q.front().d;
		q.pop();
		if (x == c && y == d) {
			printf("%d", dist); return 0;
		}
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !chk[nx][ny]) {
				chk[nx][ny] = 1;
				q.push({ nx, ny, dist + 1 });
			}
		}
	}
	printf("-1");
}