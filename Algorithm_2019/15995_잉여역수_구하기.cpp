#include<cstdio>
typedef long long ll;

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	for (int i = 1; i <= 100000000; ++i) {
		if ((a * i) % b == 1) {
			printf("%d", i); return 0;
		}
	}
}