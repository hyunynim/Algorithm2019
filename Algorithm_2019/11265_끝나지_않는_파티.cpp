#include<cstdio>
#include<algorithm>
using namespace std;
int adj[505][505];
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &adj[i][j]);
	
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (adj[a - 1][b - 1] <= c)
			puts("Enjoy other party");
		else
			puts("Stay here");
	}
}