#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;
struct MaximumFlow {
	struct Edge {
		int to;
		int capacity;
		Edge *rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {
		}
	};
	int n;
	int source, sink;
	vector<vector<Edge *>> graph;
	vector<bool> check;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
		check.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int dfs(int x, int c) {
		if (check[x]) return 0;
		check[x] = true;
		if (x == sink) {
			return c;
		}
		for (int i = 0; i<graph[x].size(); i++) {
			if (graph[x][i]->capacity > 0) {
				int nc = graph[x][i]->capacity;
				if (c != 0 && c < nc) {
					nc = c;
				}
				int f = dfs(graph[x][i]->to, nc);
				if (f) {
					graph[x][i]->capacity -= f;
					graph[x][i]->rev->capacity += f;
					return f;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (true) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};
int node(string s) {
	if (s[0] >= 'A' && s[0] <= 'Z') {
		return s[0] - 'A';
	}
	else {
		return s[0] - 'a' + 26;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	MaximumFlow mf(n + m + 2, 0, n + m + 1);
	for (int i = 0; i < n; ++i) {
		int p, k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> p;
			mf.add_edge(i + 1, n + p, 1);
		}
	}
	for (int i = 0; i < n; ++i)
		mf.add_edge(0, i + 1, 1);
	for (int i = 0; i < m; ++i)
		mf.add_edge(n + i + 1, n + m + 1, 1);
	cout << mf.flow();
}