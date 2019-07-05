#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n; cin >> n;
	ll res = 0, cur = 1;
	while (cur < n) {
		ll cnt = (n - 1) / (cur);
		ll next = (n - 1) / cnt;
		res += (cnt + 1) * (next - cur + 1);
		cur = next + 1;
	}
	cout << res + 1;
}