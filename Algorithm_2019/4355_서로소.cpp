#include<cstdio>
typedef long long ll;

ll phi(ll n) {
	ll ans = n;
	for (ll i = 2; i*i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			ans -= ans / i;
		}
	}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

int main() {
	while (1) {
		ll n;
		scanf("%lld", &n);
		if (n == 0)
			return 0;
		printf("%lld\n", phi(n));
	}
}