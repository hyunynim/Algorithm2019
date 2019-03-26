#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
vector<P> adj[10101];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	priority_queue<T> q;
	vector<ll> ans[21];
	for (int i = 0; i < 21; ++i) {
		ans[i].resize(n + 1);
		fill(ans[i].begin(), ans[i].end(), 1e14);
	}
	q.push({ 0, 1 , k});
	ans[k][1] = 0;
	while (q.size()) {
		ll cur, d, k;
		tie(d, cur, k) = q.top(); q.pop();
		if (d >= ans[k][cur]) continue;
		for (int i = 0; i < adj[cur].size(); ++i) {
			ll next = adj[cur][i].first;
			ll nd = d + adj[cur][i].second;
			if (ans[k][next] > nd) {
				ans[k][next] = nd;
				q.push({ nd, next , k });
			}
			if (k && ans[k - 1][next] > d) {
				ans[k - 1][next] = d;
				q.push({ d, next, k - 1 });
			}
		}
	}
	ll res = 1e14;
	for (int i = 0; i <= k; ++i)
		res = min(res, ans[i][n]);
	printf("%lld", res);
}