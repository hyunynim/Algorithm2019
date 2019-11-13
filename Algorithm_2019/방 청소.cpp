#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(2, 300);
uniform_int_distribution<int> d2(1, 500000);

int cache[501][501];
int bamboo[501][501];
int n;

int sur(int x, int y, int prev) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	else {
		int& ans = cache[y][x];
		int cur = bamboo[y][x];
		if (prev <= cur)
			return 0;
		if (~ans)
			return ans;
		ans = 1;
		ans = max({ ans, sur(x - 1, y, cur) + 1, sur(x + 1, y, cur) + 1, sur(x, y - 1, cur) + 1, sur(x, y + 1, cur) + 1 });
		return ans;
	}
}
void solve() {
	//TODO
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &bamboo[i][j]);
	}
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			sur(j, i, 1e9);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			ans = max(ans, cache[i][j]);
	}
	printf("%d", ans);
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 2, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 300;
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d ", cnt <= 3 ? rand() % 30 + 1 : d2(gen));
			puts("");
		}
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 20) break;
	}
}