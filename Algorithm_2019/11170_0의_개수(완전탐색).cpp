#include<cstdio>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = 0;
		for (int i = n; i <= m; ++i) {
			int cur = i;
			if (cur == 0) ++ans;
			else {
				while (cur) {
					ans += cur % 10 == 0;
					cur /= 10;
				}
			}
		}
		printf("%d\n", ans);
	}
}