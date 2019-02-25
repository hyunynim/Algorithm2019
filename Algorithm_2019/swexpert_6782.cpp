#include<cstdio>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
unordered_map<ll, ll> d;
vector<ll> sq;
const ll inf = 1234567890LL;
ll go(ll num) {
	if (num == 1)
		return 1;
	else if (num == 2)
		return 0;
	if (d[num]) return d[num];
	if (binary_search(sq.begin(), sq.end(), num))
		d[num] = go(sqrt(num)) + 1;
	else {
		ll next = *upper_bound(sq.begin(), sq.end(), num);
		int cnt = next - num;
		d[num] = go(sqrt(next)) + cnt + 1;
	}
	return d[num];
}
int main() {
	for (ll i = 2; i <= 1000000; ++i)
		sq.push_back(i * i);
	int t;
	scanf("%d", &t);
	for (int TC = 1; TC <= t; ++TC) {
		ll num;
		scanf("%lld", &num);
		ll ans = go(num);
		printf("#%d %lld\n", TC, ans);
	}
}
