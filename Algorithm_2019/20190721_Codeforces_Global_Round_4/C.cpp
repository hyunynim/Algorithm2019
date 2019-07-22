#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
	int w, h;
	scanf("%d %d", &w, &h);
	w += h;
	ll res = 1, t = 2;
	while (w) {
		if (w & 1) {
			res *= t;
			res %= mod;
		}
		t *= t;
		t %= mod;
		w >>= 1;
	}
	printf("%lld", res);
}