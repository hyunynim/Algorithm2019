typedef long long ll;
typedef pair<ll, ll> PL;
int ccw(PL s, PL p1, PL p2) {
	ll x1 = p1.first - s.first;
	ll y1 = p1.second - s.second;
	ll x2 = p2.first - s.first;
	ll y2 = p2.second - s.second;
	ll res = (x1*y2 - y1 * x2);
	return res;
}