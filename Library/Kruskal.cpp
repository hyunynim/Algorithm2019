#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#include<functional>
#include<queue>
#define MAX_SIZE 1010

using namespace std;

typedef pair<int, int> P;
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

int Kruskal(vector<pair<int, int>> & picked) {
	int res = 0;
	picked.clear();
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 0; u < v; ++u) {
		for (int i = 0; i < adj[u].size(); ++i) {
			int V = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, V)));
		}
	}
	sort(edges.begin(), edges.end());
	DISJOINT sets;
	for (int i = 0; i < edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.Find(u) == sets.Find(v)) continue;
		sets.Union(u, v);
		picked.push_back(make_pair(u, v));
		res += cost;
	}
	return res;
}

int main() {
	scanf("%d %d", &v, &m);
	int a, b, w;
	vector<int> seq;
	char c[12];
	seq.push_back(0);
	for (int i = 0; i < v; ++i) {
		scanf("%s", c);
		seq.push_back(c[0]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		if (seq[a] != seq[b]) {
			adj[a].push_back({ b, w });
			adj[b].push_back({ a, w });
		}
	}
	vector<pair<int, int>> pick;
	int ans = Kruskal(pick);
	printf("%d", pick.size() == v-1 ? ans : -1);
}