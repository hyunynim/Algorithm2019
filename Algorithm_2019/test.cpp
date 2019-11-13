#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int inf = 1000000000;
#define V_MAX 2020
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
	int a, b, c;
	freopen("tc2.in", "r", stdin);
	scanf("%d %d", &v, &e);
	scanf("%d %d %d", &a, &b, &c);
	st = v + 1;
	for (int i = 0; i < v - 1; ++i) {
		int m1, m2, m3;
		scanf("%d %d %d", &m1, &m2, &m3);
		adj[i + 2].push_back({ i + 2 + v, m1 * a + m2 * b + m3 * c });
	}
	int from, to, w;
	map<P, int> chk;
	for (int i = 0; i < e; ++i) {
		scanf("%d %d %d", &from, &to, &w);
//		if (from > to) swap(from, to);
//		if (chk[{from, to}]) continue;
//		else {
//			chk[{from, to}] = 1;
//			printf("%d %d %d\n", from, to, w);
//		}
		adj[from + v].push_back({ to, w });
		adj[to + v].push_back({ from, w });
	}
	vector<int> ans = dijkstra(st);
	int num; scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		int p;
		scanf("%d", &p);
		printf("%d\n", ans[p]);
	}
}