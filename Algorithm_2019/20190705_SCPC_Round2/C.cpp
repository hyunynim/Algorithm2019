#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct VECTOR {
	ll x, y;
};
struct LINE {
	ll s, e, h;
};
int main() {
	setbuf(stdout, NULL);
	int t; scanf("%d", &t);
	for (int TC = 1; TC <= t; ++TC) {
		ll l, s, e; scanf("%lld %lld %lld", &l, &s, &e);
		int a; scanf("%d", &a);
		vector<VECTOR> ce(a);
		vector<LINE> line;
		ll cur = 0;
		for (int i = 0; i < a; ++i) {
			scanf("%lld %lld", &ce[i].x, &ce[i].y);
			line.push_back({ cur, cur + ce[i].x, ce[i].y });
			cur += ce[i].x;
		}
		int b; scanf("%d", &b);
		vector<VECTOR> fl(b);
		cur = 0;
		for (int i = 0; i < b; ++i) {
			scanf("%lld %lld", &fl[i].x, &fl[i].y);
			line.push_back({ cur, cur + ce[i].x, -ce[i].y });
			cur += ce[i].x;
		}
		sort(line.begin(), line.end(), [](LINE l1, LINE l2) {
			return l1.s < l2.s;
			});
		for (auto i : line)
			printf("%lld %lld %lld\n", i.s, i.e, i.h);
	}
}