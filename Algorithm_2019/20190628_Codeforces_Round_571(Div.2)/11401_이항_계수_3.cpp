#include<cstdio>
typedef long long ll;
const ll mod = 1e9 + 7;
ll pow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}
int main() {
	ll n, k; scanf("%lld %lld", &n, &k);
	ll u = 1, b = 1;
	for (int i = 0; i < k; ++i) {
		u *= (n - i);
		u %= mod;
		b *= (i + 1);
		b %= mod;
	}
	printf("%lld", (u * pow(b, mod - 2)) % mod);
}