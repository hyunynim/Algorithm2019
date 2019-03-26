#include<cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int t; scanf("%d", &t);
	for (int TC = 1; TC <= t; ++TC) {
		int ans = 0, num;
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &num);
			ans = max(num, ans);
		}
		printf("Case #%d: %d\n", TC, ans);
	}
}