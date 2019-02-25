#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 20202;
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
int n, m;int compin(int x, int y) {	return x * m + y;}int compout(int x, int y) {	return compin(x, y) + n * m;}int main() {	char road[101][101];	scanf("%d %d", &n, &m);	for (int i = 0; i < n; ++i)		scanf("%s", road[i]);	int s, t;	int dx[] = { 0, 0, -1, 1 };	int dy[] = { -1, 1, 0, 0 };	for (int i = 0; i < n; ++i) {		for (int j = 0; j < m; ++j) {			if (road[i][j] == '#') continue;			add_edge(compin(i, j), compout(i, j), 1);			if (road[i][j] == 'K')				s = compout(i, j);			else if (road[i][j] == 'H')				t = compin(i, j);			for (int k = 0; k < 4; ++k) {				int nx = i + dx[k];				int ny = j + dy[k];				if (0 <= nx && nx < n && 0 <= ny && ny < m && road[nx][ny] != '#')					add_edge(compout(i, j), compin(nx, ny), 2e9);			}		}	}	ll ans = match(s, t);	printf("%lld", ans > 100000 ? -1 : ans);}