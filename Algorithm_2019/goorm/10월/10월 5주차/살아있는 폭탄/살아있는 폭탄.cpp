#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000);
struct POS {
	int x, y;
};
int board[1010][1010];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
void solve() {
	//TODO
	int n; cin >> n;
	queue<POS> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j])
				q.push({ i, j });
		}
	}
	int ans = 1;
	while (q.size()) {
		int x = q.front().x, y = q.front().y;
		ans = max(ans, board[x][y]);
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	printf("%d", ans);
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d ", rand() % 5 == 0);
			puts("");
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}