#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll d[505]; int n, m;
vector<int> seq;
ll go(int s, vector<int> & cnt) {
	if (s == m) return 1;
	ll & res = d[s];
	if (~res) return res;
	res = 0;
	int c = seq[s];
	if (cnt[c] >= s)
		res = go(s + 1, cnt);
	else {
		for (int i = m - 1; i >= s; --i) {
			int prev = cnt[c];
			cnt[c] = i;
			res += go(s + 1, cnt);
			res %= mod;
			cnt[c] = prev;
		}
	}
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &m);
	seq.resize(m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &seq[i]);
	vector<int> cnt(n + 1);
	for (int i = 0; i < cnt.size(); ++i)
		cnt[i] = -1;
	printf("%lld", go(0, cnt));
}

