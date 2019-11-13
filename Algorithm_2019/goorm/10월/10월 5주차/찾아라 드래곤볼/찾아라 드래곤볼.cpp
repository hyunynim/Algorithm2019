#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(5, 1000);
int board[1010][1010];
int chk[1010][1010];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
struct POS {
	int x, y;
};
bool solve() {
	//TODO
	memset(board, 0, sizeof(board));
	memset(chk, 0, sizeof(chk));
	int n; cin >> n;
	int ball = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	queue<POS> q;
	q.push({ 0, 0 });
	chk[0][0] = 1;
	while (q.size()) {
		int x = q.front().x, y = q.front().y;
		if (board[x][y] == 2) {
			cout << chk[x][y] - 1;
			return 1;
		}
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] != 1 && chk[nx][ny] == 0) {
				q.push({ nx, ny});
				chk[nx][ny] = chk[x][y] + 1;
			}
		}
	}
	cout << -1;
	return 0;
}
int main() {
	freopen("goorm/input.4.txt", "r", stdin);
	solve();
	return 0;
	srand(time(0));
	char msg[1010];
	int cnt = 2, tmp;
	bool chk = 0;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000;
		int ball = 1;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) {
					printf("0 ");
					continue;
				}
				int num = rand() % 5;
				if (num == 1) {
					if (ball) {
						printf("%d ", 2);
						--ball;
					}
					else
						printf("0 ");
				}
				else
					printf("%d ", num == 0);
			}
			puts("");
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		if (chk ^ solve()) --cnt;
		else chk ^= 1;
		if (cnt > 10) break;
	}
}