#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	ll ans1 = (m / 2 + m % 2) * (n / 3) + ((n % 3 != 0) * (m / 3));
	ll ans2 = (n / 2 + n % 2) * (m / 3) + ((m % 3 != 0) * (n / 3));
	ll ans = max(ans1, ans2);
	if(min(n, m) >= 5)
		ans = max({ans, (m / 5) * (n / 6) * 5 + )
	printf("%lld", max({ ans1, ans2, ((n * m) / 6) + ((n * m) % 6 / 3)}));


}