#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<cstdio>
#include<utility>
using namespace std;
typedef long long ll;
const int MAXN = 2020;
struct edg { int pos, cap, rev; };
vector<edg> gph[MAXN];
void clear() { for (int i = 0; i < MAXN; i++) gph[i].clear(); }
void add_edge(int s, int e, int x) {
	gph[s].push_back({ e, x, (int)gph[e].size() });
	gph[e].push_back({ s, 0, (int)gph[s].size() - 1 });
}
int dis[MAXN], pnt[MAXN];
bool bfs(int src, int sink) {
	memset(dis, 0, sizeof(dis));
	memset(pnt, 0, sizeof(pnt));
	queue<int> que;
	que.push(src);
	dis[src] = 1;
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (auto &e : gph[x]) {
			if (e.cap > 0 && !dis[e.pos]) {
				dis[e.pos] = dis[x] + 1;
				que.push(e.pos);
			}
		}
	}
	return dis[sink] > 0;
}
int dfs(int x, int sink, int f) {
	if (x == sink) return f;
	for (; pnt[x] < gph[x].size(); pnt[x]++) {
		edg e = gph[x][pnt[x]];
		if (e.cap > 0 && dis[e.pos] == dis[x] + 1) {
			int w = dfs(e.pos, sink, min(f, e.cap));
			if (w) {
				gph[x][pnt[x]].cap -= w;
				gph[e.pos][e.rev].cap += w;
				return w;
			}
		}
	}
	return 0;
}
ll match(int src, int sink) {
	ll ret = 0;
	while (bfs(src, sink)) {
		int r;
		while ((r = dfs(src, sink, 2e9))) ret += r;
	}
	return ret;
}
int board[101][101];
pair<int, int> boardNum[101][101];


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		char msg[123];
		scanf("%s", msg);
		for (int j = 0; j < m; ++j)
			if (msg[j] == '*') board[i][j] = 1;
	}
	int c = 1, r = 1;
	for (int i = 0; i < n; ++i) {
		bool cp = 0;
		for (int j = 0; j < m; ++j) {
			if (board[i][j]) {
				cp = 1;
				boardNum[i][j].first = c;
			}
			else if (j && board[i][j - 1]) {
				++c;
				cp = 0;
			}

		}
		if (cp)
			++c;
	}
	for (int j = 0; j < m; ++j) {
		bool rp = 0;
		for (int i = 0; i < n; ++i) {
			if (board[i][j]) {
				rp = 1;
				boardNum[i][j].second = r;
			}
			else if (i && board[i - 1][j]) {
				rp = 0;
				++r;
			}
		}
		if (rp)
			++r;
	}
	--c; --r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = boardNum[i][j].first;
			int y = boardNum[i][j].second;
			if (x && y)
				add_edge(x, y + c, 1);
		}
	}
	for (int i = 1; i <= c; ++i)
		add_edge(0, i, 1);
	for (int i = 1; i <= r; ++i)
		add_edge(i + c, r + c + 1, 1);
	printf("%lld", match(0, r + c + 1));
}