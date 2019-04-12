#include<bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> P;
const int inf = 1e9;
const int V_MAX = 1010;
vector<P> adj[V_MAX];
int v, e, st, lim;

int dijkstra(int st) {
	bool chk[V_MAX] = { 0 };
	priority_queue<P, vector<P>, greater<P>> q;
	vector<int> ans[10101];
	for (int i = 0; i <= lim; ++i) {
		ans[i].resize(V_MAX + 1);
		fill(ans[i].begin(), ans[i].end(), inf);
	}
	q.push({ 0, 0, st });
	
	int sz = 1;
	ans[0][st] = 0;
	while (q.size()) {
		int x, c, d;
		tie(d, c, x) = q.top();
		q.pop();
		if (chk[x] || c > lim)
			continue;
		chk[x] = 1;
		++sz;
		for (auto p : adj[x]) {
			int to, nc, nd;
			tie(to, nc, nd) = p;
			if (nc + c <= lim && nd + d < ans[nc][to]) {
				ans[nc][to] = nd + d;
				q.push({ nd + d, nc + c, to });
			}
		}
	}
	int res = 1e9;
	for (int i = 0; i <= lim; ++i)
		res = min(res, ans[i][v]);
	return res;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &v, &lim, &e);
		for (int i = 0; i < V_MAX; ++i)
			adj[i].clear();
		for (int i = 0; i < e; ++i) {
			int from, to, c, d;
			scanf("%d %d %d %d", &from, &to, &c, &d);
			adj[from].push_back({ to, c, d });
		}
		int ans = dijkstra(1);
		if (ans >= 1e8)
			puts("Poor KCM");
		else
			printf("%d\n", ans);
	}
}