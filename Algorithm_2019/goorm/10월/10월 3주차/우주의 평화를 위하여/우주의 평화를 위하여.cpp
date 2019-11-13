#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 10);
int board[1212][1212], ans;
void go(int x, int y, int sz) {
	if (sz == 1) {
		++ans; return;
	}
	bool stop = 0;
	int st = board[x][y];
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (board[i + x][j + y] != st) {
				stop = 1;
				break;
			}
		}
		if (stop) break;
	}
	if (stop) {
		int ns = sz / 2;
		int nx = x + ns;
		int ny = y + ns;

		go(x, y, ns);
		go(nx, y, ns);
		go(x, ny, ns);
		go(nx, ny, ns);
	}
	else
		++ans;
}
void solve() {
	//TODO
	memset(board, 0, sizeof(board));
	ans = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);
	go(0, 0, n);
	printf("%d", ans);
}
int main() {
	solve();
	return 0;
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = (1 << d1(gen));
		if (cnt <= 3)
			n = (1 << (rand() % 2 + 2));
		else if (cnt <= 6)
			n = 1024;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d ", cnt == 4 ? 0 : rand() % 3 + 1);
			puts("");
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 3) break;
	}
}