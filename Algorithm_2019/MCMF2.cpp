#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<cstdio>

using namespace std;

const int MAXN = 50005, MAXM = 50005;
vector<int> gph[MAXN];
int dis[MAXN], l[MAXN], r[MAXM], vis[MAXN];
void clear() { for (int i = 0; i < MAXN; i++) gph[i].clear(); }
void add_edge(int l, int r) { gph[l].push_back(r); }
bool bfs(int n) {
	queue<int> que;
	bool ok = 0;
	memset(dis, 0, sizeof(dis));
	for (int i = 0; i < n; i++) {
		if (l[i] == -1 && !dis[i]) {
			que.push(i);
			dis[i] = 1;
		}
	}
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto &i : gph[x]) {
			if (r[i] == -1) ok = 1;
			else if (!dis[r[i]]) {
				dis[r[i]] = dis[x] + 1;
				que.push(r[i]);
			}
		}
	}
	return ok;
}
bool dfs(int x) {
	for (auto &i : gph[x]) {
		if (r[i] == -1 || (!vis[r[i]] && dis[r[i]] == dis[x] + 1 && dfs(r[i]))) {
			vis[r[i]] = 1; l[x] = i; r[i] = x;
			return 1;
		}
	}
	return 0;
}
int match(int n) {
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	int ret = 0;
	while (bfs(n)) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) if (l[i] == -1 && dfs(i)) ret++;
	}
	return ret;
}
bool chk[MAXN + MAXM];
void rdfs(int x, int n) {
	if (chk[x]) return;
	chk[x] = 1;
	for (auto &i : gph[x]) {
		chk[i + n] = 1;
		rdfs(r[i], n);
	}
}
vector<int> getcover(int n, int m) { // solve min. vertex cover
	match(n);
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < n; i++) if (l[i] == -1) rdfs(i, n);
	vector<int> v;
	for (int i = 0; i < n; i++) if (!chk[i]) v.push_back(i);
	for (int i = n; i < n + m; i++) if (chk[i]) v.push_back(i);
	return v;
}

int main() {
	int n, m;	scanf("%d %d", &n, &m);	for (int i = 1; i <= n; ++i) {		add_edge(0, i);	}	for (int i = 0; i < n; ++i) {		int num, a; scanf("%d", &num);		for (int j = 0; j < num; ++j) {			scanf("%d", &a);			add_edge(i + 1, a + n);		}	}	for(int i = 1; i<=m; ++i)		add_edge(i + n, n + m + 1);	vector<int> ans = getcover(0, n + m + 1);	printf("%d", ans.size());
}