#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n, m;

bool chk(vector<ll> & seq, ll k) {
	ll ans = 0;
	for (int i = 0; i < seq.size(); ++i) 
		ans += k / seq[i];
	return ans >= m;
}

int main() {
	scanf("%lld %lld", &n, &m);
	vector<ll> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &seq[i]);

	ll l = 1, r = 1e18;
	ll ans = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (chk(seq, mid)) {
			if (seq.back() == -1) {
				seq.pop_back();
				r = mid;
			}
			else {
				ans = min(mid, ans);
				r = mid - 1;
			}
		}
		else l = mid + 1;
	}
	printf("%lld", ans);
}