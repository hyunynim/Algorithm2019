#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 100);
uniform_int_distribution<ll> d2(2, 10000);
uniform_int_distribution<ll> d3(1, 1000000);
const ll mod = 1e9 + 7;
ll pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n /= 2;
	}
	return res;
}
ll solve(int n, ll k, ll t) {
	ll res = ((n * ((pow(k, t) - 1 + mod) % mod) % mod) * pow(k - 1, mod - 2)) % mod;
	return res;
}
int main() {
	ll n, k, t; cin >> n >> k >> t;
	cout << solve(n, k, t);
	return 0;
	srand(time(0));
	char msg[1010];
	int cnt = 2, tmp;
	while (1) {
		sprintf(msg, "goorm/tmp/input.%d.txt", cnt);
		FILE* fp = fopen(msg, "w");
		int n = d1(gen);
		ll k = d2(gen);
		ll t = d3(gen);
		if (cnt < 5) t = 1e16;
		fprintf(fp, "%d %lld %lld", n, k, t);
		fclose(fp);
		fp = freopen(msg, "r", stdin);
		sprintf(msg, "goorm/tmp/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		ll res1 = solve(n, k, t);
		cout << res1;
		if (cnt > 10) break;
	}
}