#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505050;
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
		for
			(int pos = sink; pos != src; pos = pa[pos]) {
			cap = min(cap, gph[pa[pos]][pe[pos]].cap);
		}
		ret += dist[sink] * cap;
		for
			(int pos = sink; pos != src; pos = pa[pos]) {
			int rev = gph[pa[pos]][pe[pos]].rev;
			gph[pa[pos]][pe[pos]].cap -= cap;
			gph[pos][rev].cap += cap;
		}
	}
	return ret;
}
int board[505][505];
int main() {
	int t; scanf("%d", &t);
	int dx[] = { 0, 0, 0, -1, -1, -1, -2, -2, -2 };
	int dy[] = { 0, -1, -2, 0, -1, -2, 0, -1, -2 };
	for (int TC = 1; TC <= t; ++TC) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%1d", &board[i][j]);
				if (board[i][j]) {
					add_edge(250001 + i * m + j, 505049, 1, 0);
					for (int k = 0; k < 9; ++k) {
						int px = i + dx[k];
						int py = j + dy[k];
						if (0 <= px && 0 <= py)
							add_edge(1 + px * m + py, i * m + j + 250001, 1, 0);
					}
				}
			}
		}
		for (int i = 1; i <= n * m; ++i) {
			if (gph[i].size())
				add_edge(0, i, 9, -gph[i].size());
		}
		match(0, 505049);
		int ans = 0;
		for (int i = 0; i < gph[0].size(); ++i) {
			if (gph[0][i].cap < 9)
				++ans;
		}
		printf("Case #%d\n%d\n", TC, ans);
		for (int i = 0; i < gph[0].size(); ++i) {
			if (gph[0][i].cap < 9)
				printf("%d %d\n", (gph[0][i].pos - 1) / m + 1, (gph[0][i].pos - 1) % m + 1);
		}
		clear();
		fflush(stdout);
	}
}

//score: 12