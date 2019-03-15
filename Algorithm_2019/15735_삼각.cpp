#include<cstdio>
int main() {
	long long n;
	scanf("%lld", &n);
	printf("%lld", n*(n + 2)*(2 * n + 1) / 8);
}