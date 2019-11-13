#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct EDGE {
	ll x, w;
};
struct edge {
	int from, to;
	ll w;
};
bool operator < (edge e1, edge e2) {
	return e1.w > e2.w;
}
vector<EDGE> adj[202020];
map<pair<int, int>, int> chk;
int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	priority_queue<edge> q;
	for (int i = 0; i < m; ++i) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a > b) swap(a, b);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
		q.push({ (int)a, (int)b, c });
		chk[{a, b}] = c;
	}
	while (q.size()) {
		int f = q.top().from, t = q.top().to;
		ll w = q.top().w;
		q.pop();
		--k;
		if (k == 0) {
			printf("%lld", w);
			return 0;
		}
		for (int i = 0; i < adj[t].size(); ++i) {
			ll cur = chk[{t, (int)adj[t][i].x}];
			if (cur == 0 || w + adj[t][i].w + w < cur) {
				chk[{t, (int)adj[t][i].x}] = w + adj[t][i].w;
				q.push({ f, (int)adj[t][i].x, w + adj[t][i].w });
			}
		}
	}
}