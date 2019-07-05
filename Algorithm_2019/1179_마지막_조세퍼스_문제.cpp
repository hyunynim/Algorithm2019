#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll jo(ll n, ll k) {
	ll res = 0;
	for (int i = 1; i <= n; ++i) 
		res = (res + k) % i;
	return res;
}
ll go(ll n, ll k) {
	if (k == 1) return n - 1;
	if (n <= k) return jo(n, k);
	ll next = n - n / k;
	ll ans = go(next, k) - (n % k) + next;
	ans %= next;
	ans = ans * k / (k - 1);
	return ans;
}
int main() {
	ll n, k;
	cin >> n >> k;
	cout << go(n, k) + 1;
}