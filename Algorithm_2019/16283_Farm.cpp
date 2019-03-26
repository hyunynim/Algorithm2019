#include<cstdio>

int main() {
	int a, b, n, w;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	int cnt = 0;
	int ans1, ans2;
	for (int i = 1; i < n; ++i) {
		if (a * i + b * (n - i) == w) {
			++cnt;
			ans1 = i; ans2 = n - i;
			if (cnt == 2) {
				printf("-1"); return 0;
			}
		}
	}
	if (cnt == 1)
		printf("%d %d", ans1, ans2);
	else
		printf("-1");
}