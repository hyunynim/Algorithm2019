#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
#include<functional>
#include<string.h>
using namespace std;
vector<int> adj[101];
priority_queue<pair<int, int>> grp[101];
bool chk[101];
int dfs(int s) {
	int ret = 0;
	for (int i = 0; i < adj[s].size(); ++i) {
		int next = adj[s][i];
		if (!chk[next]) {
			chk[next] = 1;
			int k = dfs(next) + 1;
			grp[s].push({ k, next });
			ret = max(ret, k);
		}
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int num; scanf("%d", &num);
		if (i)
			adj[num].push_back(i);
	}
	dfs(0);
	memset(chk, 0, sizeof(chk));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	chk[0] = 1;
	int ans = 0;
	while (q.size()) {
		int cur, d;
		tie(d, cur) = q.front(); q.pop();
		ans = max(d, ans);
		while(grp[cur].size()){
			int next = grp[cur].top().second; grp[cur].pop();
			if (!chk[next]) {
				chk[next] = 1;
				q.push({ ++d, next });
			}
		}
	}
	printf("%d", ans);
}