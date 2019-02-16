#include<cstdio>
#include<cmath>
int gcd(int a, int b) {
	if (b) return gcd(b, a % b);
	return a;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int c, d;
	int minM = 2e9;
	int j = 32767;
	for (int i = 1; i < 32767; ++i) {
			if (minM > abs(a * j - b * i)) {
				minM = abs(a * j - b * i);
				c = i; d = j;
			}
	}
	printf("%d %d", c, d);
}