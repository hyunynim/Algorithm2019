#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#include<functional>
#include<queue>
const int MAX_SIZE = 1010;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
vector<P> adj[MAX_SIZE];
bool chk[MAX_SIZE];
int v, m;
struct DISJOINT {
	vector<int> p;
	vector<int> sz;
	DISJOINT() {
		p.resize(MAX_SIZE);
		sz.resize(MAX_SIZE);
		for (int i = 0; i < MAX_SIZE; ++i) {
			p[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int x) {
		if (x == p[x])
			return  x;
		else
			return p[x] = Find(p[x]);
	}
	int Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) {
			p[y] = x;
			sz[y] = sz[x] += sz[y];
		}
		return sz[x];
	}
};

ll Kruskal(vector<P> & picked) {
	ll res = 0;
	picked.clear();
	vector<pair<ll, P>> edges;
	for (int u = 0; u < v; ++u) {
		for (int i = 0; i < adj[u].size(); ++i) {
			ll V = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back({ cost, {u, V} });
		}
	}
	sort(edges.begin(), edges.end());
	DISJOINT sets;
	for (int i = 0; i < edges.size(); ++i) {
		ll cost = edges[i].first;
		ll u = edges[i].second.first, v = edges[i].second.second;
		if (sets.Find(u) == sets.Find(v)) continue;
		sets.Union(u, v);
		picked.push_back({ u, v });
		res += cost;
	}
	return res;
}

int main() {
	ll c; scanf("%d", &v);
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			scanf("%lld", &c);
			if (i == j) continue;
			adj[i].push_back({ j, c });
		}
	}
	vector<P> pick;
	ll ans = Kruskal(pick);
	printf("%lld", ans);
}