#include<cstdio>
#include<vector>
typedef long long ll;
using namespace std;

void FindDiv(vector<ll> & div, ll n) {
	for (ll i = 2; i*i <= n; ++i) {
		if (n % i == 0)
			div.push_back(i);
	}
	for (ll i = div.size() - 1; i >= 0; --i) {
		if (i == div.size() - 1 && n / div[i] == div.back())
			continue;
		div.push_back(n / div[i]);
	}
	div.push_back(n);
}

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
//999999937 (1000000007 이전 소수)
int main() {
	ll n;
	scanf("%lld", &n);
	vector<ll> vtmp;
	FindDiv(vtmp, n);
//	FindPrimeFact(vtmp, n);
	for (int i = 0; i < vtmp.size(); ++i) {
		printf("%lld\n", vtmp[i]);
	}

}