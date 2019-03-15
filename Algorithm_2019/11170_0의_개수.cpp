#include<cstdio>

int ans[1010101];

int main() {
	ans[0] = 1;
	int t; scanf("%d", &t);
	for (int i = 1; i <= 1000001; ++i) {
		int cur = i;
		ans[i] = ans[i - 1];
		while (cur) {
			ans[i] += cur % 10 == 0;
			cur /= 10;
		}
	}
	int n, m;
	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &n, &m);
		if (n)
			printf("%d\n", ans[m] - ans[n - 1]);
		else
			printf("%d\n", ans[m]);
	}
}