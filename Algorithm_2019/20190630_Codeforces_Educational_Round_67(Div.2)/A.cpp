#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll n, s, t;
		scanf("%lld %lld %lld", &n, &s, &t);
		printf("%lld\n", n - min(s, t) + 1);
	}
}