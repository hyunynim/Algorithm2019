#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
struct POS {
	int x, y;
	int f[4];
};
int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);
		vector<POS> seq(n);
		vector<pair<int, int>> ln[2];
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &seq[i].x, &seq[i].y);
			for (int j = 0; j < 4; ++j)
				scanf("%d", &seq[i].f[j]);
			ln[0].push_back({ seq[i].x - seq[i].f[0], seq[i].x + seq[i].f[2] });
			ln[1].push_back({ seq[i].y - seq[i].f[3], seq[i].y + seq[i].f[1] });
		}
		sort(ln[0].begin(), ln[0].end());
		sort(ln[1].begin(), ln[1].end());
		int mx = ln[0][0].first, Mx = ln[0][0].second;
		int my = ln[1][0].first, My = ln[1][0].second;
		int ansX, ansY;
		bool hasAns = 1;
		for (int i = 1; i < n; ++i) {
			if (ln[0][i].second < mx || ln[0][i].first > Mx || ln[1][i].second < my || ln[1][i].first > My) {
				hasAns = 0;
				break;
			}
			mx = max(mx, ln[0][i].first);
			Mx = min(Mx, ln[0][i].second);
			my = max(my, ln[1][i].first);
			My = min(My, ln[1][i].second);
			mx = max(mx, (int)-1e5);
			Mx = min(Mx, (int)1e5);
			my = max(my, (int)-1e5);
			My = min(My, (int)1e5);
		}
		if (hasAns) {
			printf("1 %d %d\n", mx, my);
		}
		else
			puts("0");
	}
}