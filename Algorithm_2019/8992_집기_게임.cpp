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

struct LINE { int x1, x2, y1, y2, w;};
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<LINE> line[2];
		line[0].resize(n); line[1].resize(m);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < (i ? m : n); ++j) {
				scanf("%d %d %d %d %d", &line[i][j].x1, &line[i][j].y1,
					&line[i][j].x2, &line[i][j].y2, &line[i][j].w);
				if (line[i][j].x1 > line[i][j].x2)
					swap(line[i][j].x1, line[i][j].x2);
				if (line[i][j].y1 > line[i][j].y2)
					swap(line[i][j].y1, line[i][j].y2);
			}
		}
		for (int i = 0; i < n; ++i) {
			mcmf.add_edge(0, i + 1, 1, 0);
			for (int j = 0; j < m; ++j) {
				if ((line[1][j].y1 <= line[0][i].y1 && line[0][i].y1 <= line[1][j].y2)
					&& (line[0][i].x1 <= line[1][j].x1 && line[1][j].x1 <= line[0][i].x2))
					mcmf.add_edge(i + 1, n + j + 1, 1, -(line[0][i].w * line[1][j].w));
			}
		}
		for (int i = 0; i < m; ++i)
			mcmf.add_edge(i + n + 1, n + m + 1, 1, 0);
		int cnt = 0, ans = mcmf.match(0, n + m + 1);
		for (int i = 0; i < mcmf.gph[n + m + 1].size(); ++i)
			cnt += mcmf.gph[n + m + 1][i].cap;

		printf("%d %d\n", cnt, -ans);
		mcmf.clear();
		line[0].clear(); line[1].clear();
	}
}