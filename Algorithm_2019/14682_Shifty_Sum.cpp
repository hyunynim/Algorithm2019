#include<cstdio>
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = n;
	for (int i = 0; i < k; ++i) {
		n *= 10;
		ans += n;
	}
	printf("%d", ans);
}