#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

bool board[2][101010];
struct POS {
	int x, y, d;
};
int main() {
	freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%1d", &board[i][j]);
	queue<POS> q;
	q.push({ 0, 0, 1 });
	while (q.size()) {
		int x, y, d;
		x = q.front().x;
		y = q.front().y;
		d = q.front().d;
		q.pop();
		int next[] = { y + 1, y - 1, y + k };
		for (int i = 0; i < 3; ++i) {
			if (next[i] >= n) {
				printf("1"); return 0;
			}
			if (i == 2 && board[(x + 1) % 2][next[i]] && d <= next[i])
				q.push({ (x + 1) % 2, next[i], d + 1 });
			else if (board[x][next[i]] && d <= next[i])
				q.push({ x, next[i], d + 1 });
		}
	}
	printf("0");
}