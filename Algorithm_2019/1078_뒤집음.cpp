#include<cstdio>

int rev(int n) {
	int res = 0;
	while (n) {
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; ; ++i) {
		int res = i - rev(i);
		if (i - rev(i) == n) {
			printf("%d", i); return 0;
		}
	}
}