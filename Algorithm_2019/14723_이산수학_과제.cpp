#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1;; ++i) {
		int u = i, b = 1;
		for (int j = 0; j < i; ++j) {
			--n;
			if (n == 0) {
				printf("%d %d", u, b);
				return 0;
			}
			--u;
			++b;
		}
	}
}