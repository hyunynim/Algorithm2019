#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<functional>

using namespace std;
typedef pair<int, int> P;
const int inf = 1000000000;
#define V_MAX 543
vector<P> adj[V_MAX];
int v, e, st;

vector<int> dijkstra(int st) {
	bool chk[V_MAX] = { 0 };
	priority_queue<P, vector<P>, greater<P>> q;
	vector<int> ans;
	ans.resize(V_MAX + 1);

	q.push({ 0, st });
	fill(ans.begin(), ans.end(), inf);
	int sz = 1;
	ans[st] = 0;
	while (q.size()) {
		int x = q.top().second;
		int d = q.top().first;
		q.pop();
		if (chk[x])
			continue;
		chk[x] = 1;
		++sz;
		for (auto p : adj[x]) {
			if (p.second + d < ans[p.first]) {
				ans[p.first] = p.second + d;
				q.push({ p.second + d , p.first });
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d %d %d", &v, &e, &st);
	int a, b, w;
	for (int i = 0; i < e; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back({ b, w });
	}
	vector<int> ans = dijkstra(st);
	for (int i = 1; i <= v; ++i) {
		if (ans[i] < inf)
			printf("%d\n", ans[i]);
		else
			printf("INF\n");
	}
}