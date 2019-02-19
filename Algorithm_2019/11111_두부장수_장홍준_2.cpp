#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<utility>
#include<iostream>
#include<map>
#include<string>
using namespace std;
const int MAXN = 2525;
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
int price[5][5] = { {10, 8, 7, 5, 1},
						{8, 6, 4, 3, 1},
						{7, 4, 3, 2, 1},
						{5, 3, 2, 2, 1},
						{1, 1, 1, 1, 0} };

map<string, int> p;

int main() {
	string s = "ABCDF";
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			string str = "";
			str += s[i];
			str += s[j];
			p[str] = price[i][j];
		}
	}

	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; ++i)
		cin >> board[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i || j) {
				mcmf.add_edge(i * n + j + 1, 2524, 1, 0);
			}
			if (i != n - 1 && j != m - 1) {
				mcmf.add_edge(0, i * n + j + 1, 1, 0);
			}
			if (j < m - 1) {
				string str = "";
				str += board[i][j];
				str += board[i][j + 1];
				mcmf.add_edge(i * n + j + 1, i * n + j + 2, 1, -p[str]);
			}
			if (i < n - 1) {
				string str = "";
				str += board[i][j];
				str += board[i + 1][j];
				mcmf.add_edge(i * n + j + 1, (i + 1) * n + j + 1, 1, -p[str]);
			}
		}
	}
	printf("%d", mcmf.match(0, 2524));
}