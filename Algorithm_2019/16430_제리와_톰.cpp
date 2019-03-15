#include<cstdio>
int gcd(int a, int b) {
	if (b) return gcd(b, a%b);
	return a;
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d", b - a / gcd(b - a, b), b / gcd(b - a, b));
}