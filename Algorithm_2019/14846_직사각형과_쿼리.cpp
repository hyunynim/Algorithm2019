#include<cstdio>

int cnt[11][303][303];
int num[303][303];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &num[i][j]);
			cnt[num[i][j]][i][j] = 1;
			for (int k = 1; k <= 10; ++k) {
				cnt[k][i][j] += cnt[k][i - 1][j] + cnt[k][i][j - 1];
				cnt[k][i][j] -= cnt[k][i - 1][j - 1];
			}
		}
	}
	int q; scanf("%d", &q);

	for (int i = 0; i < q; ++i) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int ans = 0;
		for (int j = 1; j <= 10; ++j) {
			cnt[j][c][d] -= cnt[j][a - 1][d];
			cnt[j][c][d] -= cnt[j][c][b - 1];
			cnt[j][c][d] += (cnt[j][a - 1][b - 1]);
			if (cnt[j][c][d] > 0) ++ans;
			cnt[j][c][d] += cnt[j][a - 1][d];
			cnt[j][c][d] += cnt[j][c][b - 1];
			cnt[j][c][d] -= (cnt[j][a - 1][b - 1]);
		}
		printf("%d\n", ans);
	}
}