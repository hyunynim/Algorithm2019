#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, c;
		scanf("%d %d", &n, &c);
		printf("%d\n", n / c + (n % c != 0));
	}
}