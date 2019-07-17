#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
int main() {
	int n; scanf("%d", &n);
	ll sum[24] = { 0 };
	ll ans = 0, mod = 998244353;
	char msg[101];
	int sz = 0, ok = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; msg[j] != '\0'; ++j) {
			if (ok) ++sz;
			sum[j * 2] += (msg[j] - '0') * n;
			sum[j * 2] %= mod;
			sum[j * 2 + 1] += (msg[j] - '0') * n;
			sum[j * 2 + 1] %= mod;
		}
		if (ok) ok = 0;
	}
	
	for (int i = 0; i < sz * 2; ++i) {
		ans = ans * 10 + sum[i];
		ans %= mod;
	}
	printf("%lld", ans);
}