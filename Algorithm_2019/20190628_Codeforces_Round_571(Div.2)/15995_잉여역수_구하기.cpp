#include<cstdio>
int main() {
	int a, b; scanf("%d %d", &a, &b);
	for (int i = 1;; ++i) {
		if ((a * i) % b == 1) {
			printf("%d", i); return 0;
		}
	}
}