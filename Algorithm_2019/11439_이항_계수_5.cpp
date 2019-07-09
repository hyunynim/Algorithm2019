#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sieve[4040404] = { 1, 1 };
ll pow(ll a, ll n, ll m) {
	ll res = 1;
	return res;
}
int main() {
	ll n, r, m; scanf("%lld %lld %lld", &n, &r, &m);
	for (int i = 2; i * i <= n; ++i) {
		if (sieve[i]) continue;
		for (int j = i * i; j <= n; j += i)
			sieve[j] = 1;
	}
	vector<ll> p;
	for (int i = 2; i <= n; ++i)
		if (!sieve[i]) p.push_back(i);
	vector<ll> cnt(p.size());
	for (int i = 0; i < p.size(); ++i) 
		for (ll j = p[i]; j <= n; j *= p[i]) 
			cnt[i] += ((n / j) - (r / j) - ((n - r) / j));
	ll res = 1;
	for (int i = 0; i < cnt.size(); ++i) {
		while (cnt[i]) {
			if (cnt[i] & 1) {
				res *= p[i];
				res %= m;
			}
			p[i] *= p[i];
			p[i] %= m;
			cnt[i] >>= 1;
		}
		if (res == 0) {
			printf("0"); return 0;
		}
	}
	printf("%lld", res);
}