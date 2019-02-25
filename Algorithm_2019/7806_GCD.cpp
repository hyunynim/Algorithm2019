#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

void FindPrimeFact(vector<ll> & fact, ll n) {
	while (n > 1) {
		bool isPrime = 1;
		for (ll i = 2; i*i <= n; ++i) {
			if (n % i == 0) {
				fact.push_back(i);
				n /= i;
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			fact.push_back(n);
			return;
		}
	}
}
int cnt(ll n, ll k, vector<ll> & vtmp) {
	int c = upper_bound(vtmp.begin(), vtmp.end(), k) - lower_bound(vtmp.begin(), vtmp.end(), k);
	int res = 0; ll cur = k;
	for (int i = 1; cur < 1e9 + 1 && res < c; ++i) {
		res += n / cur;
		cur *= k;
	}
	return min(c, res);
}

ll pow(ll a, int b) {
	ll res = 1;
	while (b) {
		if (b % 2)
			res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}
int main() {
	ll a, b;
	while (~scanf("%lld %lld", &a, &b)) {
		vector<ll> vtmp;
		FindPrimeFact(vtmp, b);
		ll res = 1;
		for (int i = 0; i < vtmp.size();) {
			ll cur = vtmp[i];
			res *= pow(vtmp[i], cnt(a, vtmp[i], vtmp));
			while (i < vtmp.size() && cur == vtmp[i])++i;
		}
		printf("%lld\n", res);
		vtmp.clear();
	}
}