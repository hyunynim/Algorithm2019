#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<utility>
#include<cstdio>

using namespace std;
const int MAXN = 1010;
struct mincostflow {
	struct edg { int pos, cap, rev, cost; };
	vector<edg> gph[MAXN];
	void clear() {
		for (int i = 0; i < MAXN; i++) gph[i].clear();
	}
	void add_edge(int s, int e, int x, int c) {
		gph[s].push_back({ e, x, (int)gph[e].size(), c });
		gph[e].push_back({ s, 0, (int)gph[s].size() - 1, -c });
	}
	int dist[MAXN], pa[MAXN], pe[MAXN];
	bool inque[MAXN];
	bool spfa(int src, int sink) {
		memset(dist, 0x3f, sizeof(dist));
		memset(inque, 0, sizeof(inque));
		queue<int> que;
		dist[src] = 0;
		inque[src] = 1;
		que.push(src);
		bool ok = 0;
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (x == sink) ok = 1;
			inque[x] = 0;
			for (int i = 0; i < gph[x].size(); i++) {
				edg e = gph[x][i];
				if (e.cap > 0 && dist[e.pos] > dist[x] + e.cost) {
					dist[e.pos] = dist[x] + e.cost;
					pa[e.pos] = x;
					pe[e.pos] = i;
					if (!inque[e.pos]) {
						inque[e.pos] = 1;
						que.push(e.pos);
					}
				}
			}
		}
		return ok;
	}
	int match(int src, int sink) {
		int ret = 0;
		while (spfa(src, sink)) {
			int cap = 1e9;
			for (int pos = sink; pos != src; pos = pa[pos])
				cap = min(cap, gph[pa[pos]][pe[pos]].cap);

			ret += dist[sink] * cap;
			for (int pos = sink; pos != src; pos = pa[pos]) {
				int rev = gph[pa[pos]][pe[pos]].rev;
				gph[pa[pos]][pe[pos]].cap -= cap;
				gph[pos][rev].cap += cap;
			}
		}
		return ret;
	}
}mcmf;

int cap[101][101];
int cost[101][101];

int main() {
	int n, m, need, book;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &need);
		mcmf.add_edge(i + m + 1, m + n + 1, need, 0);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &book);
		mcmf.add_edge(0, i + 1, book, 0);
	}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &cap[i][j]);



	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if(cap[i][j])
				mcmf.add_edge(i + 1, j + m + 1, cap[i][j], cost[i][j]);

	int ans = mcmf.match(0, n + m + 1);
	int cnt = 0;
	for (int i = 0; i < mcmf.gph[n + m + 1].size(); ++i)
		cnt += mcmf.gph[n + m + 1][i].cap;
	printf("%d", cnt);
}