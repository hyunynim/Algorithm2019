#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	for (int j = 0; j < n; ++j) {
		printf("%d: ", j);
		for (int i = 1; i < (1 << n); ++i) {
			if (i & (1 << j))
				printf("%d ", i);
		}
		puts("");
	}
	int has;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &has);
		ans |= (has << i);
	}
	printf("니가 고른 수는 %d 이겁니다", ans);
}