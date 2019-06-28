#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
vector<int> adj[303030];
vector<int> seq;
bool chk[303030];
int leaf[303030];
int m = 1, M;
int dfs(int s, int & maxPath) {
	chk[s] = 1;
	if (adj[s].empty()) {
		maxPath &= seq[s];
		return 1;
	}
	int & res = leaf[s];
	int k = 0;
	for (int i = 0; i < adj[s].size(); ++i) {
		int next = adj[s][i];
		if (!chk[next]) {
			res += dfs(next);
		}
	}
	return res;
}
int go(int s) {
	chk[s] = 1;
	if (adj[s].empty()) {
		int res = M;
		--M;
		return res;

	}
	int res = seq[s] ? -1e9 : 1e9;
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < adj[s].size(); ++i)
		q.push({ -leaf[adj[s][i]], adj[s][i] });
	for (int i = 0; i < adj[s].size(); ++i) {
		int next = q.top().second;
		q.pop();
		if (!chk[next]) {
			if (seq[s])
				return go(next);
			else
				res = min(res, go(next));
		}
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	seq.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 2; i <= n; ++i) {
		int a; scanf("%d", &a);
		adj[a].push_back(i);
	}
	M = dfs(1);
	memset(chk, 0, sizeof(chk));
	printf("%d", go(1));
}