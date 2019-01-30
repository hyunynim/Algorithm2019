#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#include<functional>
#include<queue>
#include<map>
#define MAX_SIZE 202020

using namespace std;
typedef long long ll;
typedef pair<int, ll> P;
vector<P> adj[MAX_SIZE];
bool chk[MAX_SIZE];
int v, m;
int ans;
map<pair<int, int>, bool> check;
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

ll Kruskal(vector<pair<int, ll>> & picked) {
	int res = 0;
	picked.clear();
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 0; u < v; ++u) {
		for (int i = 0; i < adj[u].size(); ++i) {
			ll V = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, V)));
		}
	}
	sort(edges.begin(), edges.end());
	DISJOINT sets;
	ll prev = -1;
	for (int i = 0; i < edges.size(); ++i) {
		ll cost = edges[i].first;
		ll u = edges[i].second.first, v = edges[i].second.second;
		if (sets.Find(u) == sets.Find(v)) {
			if (check[{u, v}] == 0 && prev == cost) {
				check[{u, v}] = 1;
				check[{v, u}] = 1; ++ans;
			}
			continue;
		}
		sets.Union(u, v);
		picked.push_back(make_pair(u, v));
		res += cost;
		prev = cost;
		check[{u, v}] = 1;
		check[{v, u}] = 1;
	}
	return res;
}

int main() {
	scanf("%d %d", &v, &m);
	int a, b, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}
	vector<pair<int, ll>> pick;
	Kruskal(pick);
	printf("%d", ans);
}