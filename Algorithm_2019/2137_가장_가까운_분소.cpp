#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return (a / g) * (b / g) * g;
}
int main() {
	ll a, b, g;
	scanf("%lld %lld", &a, &b);
	g = gcd(a, b);
	a /= g;
	b /= g;
	ll ansu = 32768, ansb = 32766;
	for (ll i = 2; i <= 32767; ++i) {
		for (ll j = 1; j < i; ++j) {
			g = gcd(i, j);
			ll c = i / g;
			ll d = j / g;
			if (c == b && a == d) continue;;
			ll mo = lcm(i, b);
			ll ja = abs(a * (mo / b) - j * (mo / i));
			g = gcd(mo, ja);
			mo /= g;
			ja /= g;
			if (ansu * mo - ansb * ja > 0) {
				ansu = ja;
				ansb = mo;
			}
		}
	}
	ll mo = lcm(ansb, b);
	ll ja = abs((a * (mo / b) - ansu * (mo / ansb)));
	printf("%lld %lld", ja, mo);
	puts("");
}