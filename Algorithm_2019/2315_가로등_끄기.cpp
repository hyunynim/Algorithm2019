#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll d[1010][1010][2];
const ll inf = 12345678900LL;
vector<pair<int, ll>> seq;
ll sum;
ll go(int l, int r, int s, ll sum) {
	if (l <= 0 || r > n) return inf;
	if (l == 1 && r == n)
		return 0LL;

	ll & res = d[l][r][s == l ? 0 : 1];
	if (res != -1) return res;
	res = inf;
	int dis1 = abs(seq[s].first - seq[l - 1].first);
	int dis2 = abs(seq[s].first - seq[r + 1].first);
	ll cur = seq[s].second;
	ll next = sum - cur;
	return res = min({ res, go(l - 1, r, l - 1, next) + dis1 * next, go(l, r + 1, r + 1, next) + dis2 * next });
}

int main() {
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &m);
	seq.resize(n + 2);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %lld", &seq[i].first, &seq[i].second);
		sum += seq[i].second;
	}
	printf("%lld", go(m, m, m, sum));
}
