#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	ll x, y; scanf("%lld %lld", &x, &y);
	if (x > y) swap(x, y);
	printf("%lld", y  +  x - gcd(x, y));
}