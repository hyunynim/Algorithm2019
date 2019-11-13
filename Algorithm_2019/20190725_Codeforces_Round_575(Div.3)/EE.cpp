#include<bits/stdc++.h>
using namespace std;
bool bw(int x, int y) {
	if ((x % 2 && y % 2)
		|| (x % 2 == 0 && y % 2 == 0))
		return 1; //white
	return 0;	//black
}
map<pair<int, int>, int> chk[2];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int b[2], w[2]; scanf("%d %d", &b[0], &w[0]);
		b[1] = b[0];
		w[1] = w[0];
		queue<pair<int, int>> q[2];
		vector<pair<int, int>> ans[2];
		int sx1 = 1e6, sy1 = 1e6, sx2 = 1e6, sy2 = 1e6 - 1;

		q[0].push({ 1000000, 1000000 });
		ans[0].push_back({ 1000000, 1000000 });
		--w[0];

		q[1].push({ 1000000, 999999 });
		ans[1].push_back({ 1000000, 999999 });
		--b[1];

		chk[0][{sx1, sy1}] = 1;
		chk[1][{sx2, sy2}] = 1;
		bool noAns = 1;
		for (int t = 0; t < 2; ++t) {
			while (q[t].size()) {
				int x, y;
				tie(x, y) = q[t].front(); q[t].pop();
				if (b[t] == 0 && w[t] == 0)
					break;
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (chk[t][{nx, ny}] == 0 && 0 <= nx && nx <= 1000000000 && 0 <= ny && ny <= 1000000000) {
						chk[t][{nx, ny}] = 1;
						if (bw(nx, ny) && w[t]) {
							--w[t];
							q[t].push({ nx, ny });
							ans[t].push_back({ nx, ny });
						}
						if (!bw(nx, ny) && b[t]) {
							--b[t];
							q[t].push({ nx, ny });
							ans[t].push_back({ nx, ny });
						}
					}
				}
			}
			if (b[t] == 0 && w[t] == 0) {
				noAns = 0;
				puts("YES");
				for (int i = 0; i < ans[t].size(); ++i)
					printf("%d %d\n", ans[t][i].first, ans[t][i].second);
				break;
			}
		}
		if (noAns)
			puts("NO");
		for (int i = 0; i < 2; ++i) {
			chk[i].clear();
			ans[i].clear();
			while (q[i].size()) q[i].pop();
		}
	}
}