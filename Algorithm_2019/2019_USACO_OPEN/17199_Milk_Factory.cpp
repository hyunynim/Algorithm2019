#include<bits/stdc++.h>
using namespace std;
int adj[101][101];
int main() {
	memset(adj, 0x3f, sizeof(adj));
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int from, to; scanf("%d %d", &from, &to);
		adj[to][from] = 1;
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 1; i <= n; ++i) {
		bool ok = 1;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (adj[i][j] > 100 || adj[i][j] == 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			printf("%d", i); return 0;
		}
	}
	printf("-1");
}