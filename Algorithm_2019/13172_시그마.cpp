#include<cstdio>

typedef long long ll;
const ll mod = 1e9 + 7;
ll pow(ll a, int n) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}
ll gcd(ll a, ll b) {
	if (b) return gcd(b, a % b);
	return a;
}
int main() {
	int n; scanf("%d", &n);
	ll up = 0, bot = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll g = gcd(a, b);
		a /= g; b /= g;
		ans += b * pow(a, mod - 2) % mod;
		ans %= mod;
	}
	printf("%lld", ans);
}