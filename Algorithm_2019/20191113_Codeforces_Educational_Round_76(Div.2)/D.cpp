#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
struct HERO {
	int p, s;
};
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int mM = 0, mS = 0;
		vector<int> mon(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &mon[i]);
			mM = max(mM, mon[i]);
		}
		int m; scanf("%d", &m);
		vector<HERO> seq(m);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &seq[i].p, &seq[i].s);
			mS = max(mS, seq[i].p);
		}
		if (mM > mS) {
			puts("-1");
			continue;
		}
		int ans = 0;
		sort(seq.begin(), seq.end(), [](HERO h1, HERO h2) {
			return h1.s == h2.s ? h1.p > h2.p : h1.s > h2.s;
			});
		for (int i = 0; i < seq.size(); ++i) {
			int cnt = 0;
			vector<int> tmp;
			for (int j = 0; j < mon.size(); ++j) {
				if (mon[j] > seq[i].p) {
					ans += cnt / seq[i].s + (cnt % seq[i].s != 0);
					tmp.push_back(mon[j]);
					cnt = 0;
				}
				else
					++cnt;
			}
			if(cnt)
				ans += cnt / seq[i].s + (cnt % seq[i].s != 0);
			mon = tmp;
			tmp.clear();
		}
		printf("%d\n", ans);
	}
}