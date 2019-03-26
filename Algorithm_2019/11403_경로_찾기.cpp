#include<cstdio>
#include<algorithm>

using namespace std;

int adj[101][101];
int main() {
	int n, num; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			adj[i][j] = 1e9;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &num);
			if (num)
				adj[i][j] = num;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", adj[i][j] > 1e8 ? 0 : 1);
		puts("");
	}
}