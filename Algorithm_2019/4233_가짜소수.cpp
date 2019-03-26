#include<cstdio>

typedef long long ll;
bool isPrime(ll a) {
	if (a % 2 == 0) return 0;
	for (ll i = 3; i * i <= a; i += 2)
		if (a % i == 0) return 0;
	return 1;
}
ll pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res;
}

int main() {
	while (1) {
		ll p, a;
		scanf("%lld %lld", &p, &a);
		if (p == 0 && a == 0)
			return 0;
		if (isPrime(p))
			puts("no");
		else {
			if (pow(a, p, p) == a)
				puts("yes");
			else
			puts("no");
		}
	}
}