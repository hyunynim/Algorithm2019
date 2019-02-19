#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<utility>
#include<cstdio>

using namespace std;
const int MAXN = 2020;
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

struct LINE { int x1, x2, y1, y2, w; };
int main() {
	int v, e;
	while (~scanf("%d %d", &v, &e)) {
		for (int i = 1; i <= v; ++i) {
			if (i != 1 && i != v)
				mcmf.add_edge(i, v + i, 1, 0);
			else
				mcmf.add_edge(i, v + i, 1e9, 0);
		}
		for (int i = 0; i < e; ++i) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			mcmf.add_edge(a + v , b, 1, w);
		}
		mcmf.add_edge(0, 1, 2, 0);
		mcmf.add_edge(v, 2 * v + 1, 2, 0);
		printf("%d\n", mcmf.match(0, 2 * v + 1));
		mcmf.clear();
	}
}