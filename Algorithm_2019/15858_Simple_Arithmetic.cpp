#include<cstdio>
typedef long long ll;
int main() {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	a *= b;
	printf("%lld.", a / c);
	a %= c;
	for (int i = 0; i < 7; ++i) {
		a *= 10;
		printf("%lld", a / c);
		a %= c;
	}
}