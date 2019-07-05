#include<cstdio>
typedef long long ll;
typedef struct POLY {
	ll n, x, y;
} poly;

poly euclid(ll a, ll b) {
	poly p[3] = { { a, 1, 0 },{ b, 0, 1 } };
	while (p[1].n > 0) {
		ll k = p[0].n / p[1].n;

		p[2].n = p[0].n % p[1].n;
		p[2].x = p[0].x - k * p[1].x;
		p[2].y = p[0].y - k * p[1].y;

		p[0] = p[1];
		p[1] = p[2];
	}
	return p[0];
}
