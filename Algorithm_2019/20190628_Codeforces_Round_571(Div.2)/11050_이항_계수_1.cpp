#include<cstdio>
int main() {
	int n, k; scanf("%d %d", &n, &k);
	int u = 1, b = 1;
	for (int i = 0; i < k; ++i) {
		u *= (n - i);
		b *= (i + 1);
	}
	printf("%d", u / b);
}